#include <iostream>
#include <QDateTime>

#include "appointment.h"
#include "calendarmainwindow.h"
#include "ui_calendarmainwindow.h"
#include "appointmentui.h"


CalendarMainWindow::CalendarMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CalendarMainWindow) {

    ui->setupUi(this);


    QTableWidget* table = ui->appointmentTable;
    QStringList headerLabels;
    headerLabels << "Starttid" << "Sluttid" << "Navn";
    table->setColumnCount(headerLabels.count());
    table->setHorizontalHeaderLabels(headerLabels);
    table->horizontalHeader()->setResizeMode(0, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setResizeMode(1, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setResizeMode(headerLabels.count()-1, QHeaderView::Stretch);

    insert();

    connect(ui->addAppointmentButton,SIGNAL(clicked()),this,SLOT(on_newAppointmentButton()));
}

CalendarMainWindow::~CalendarMainWindow() {
    delete ui;
}


void CalendarMainWindow::insert() const {
    QDateTime start(QDate(2012,11,15), QTime(13, 00));
    QDateTime end(QDate(2012,11,15), QTime(14, 00));
    Appointment appointment(start, end, "Avtalenavn", "b", "c", "d", "e");


    QTableWidget* table = ui->appointmentTable;
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(appointment.getStartTime().time().toString()));
    table->setItem(row, 1, new QTableWidgetItem(appointment.getEndTime().time().toString()));
    table->setItem(row, 2, new QTableWidgetItem(appointment.getAppointmentName()));

}

void CalendarMainWindow::on_gotoTodayButton_clicked() {

}

void CalendarMainWindow::on_calendarWidget_clicked(const QDate &date) {
    ui->chosenDateLabel->setText(date.toString());
}

void CalendarMainWindow::on_newAppointmentButton()
{
    AppointmentUi appui = AppointmentUi();
    appui.show();
}
