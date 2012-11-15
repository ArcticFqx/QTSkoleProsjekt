#include <iostream>
#include <QDateTime>

#include "appointment.h"
#include "calendarmainwindow.h"
#include "ui_calendarmainwindow.h"


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
    table->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);

    load();
    on_calendarWidget_clicked(QDate::currentDate());
    //table->sortByColumn(0, Qt::AscendingOrder);
}

CalendarMainWindow::~CalendarMainWindow() {
    delete ui;
}


void CalendarMainWindow::load() {
    QDateTime start(QDate(2012,11,15), QTime(13,00));
    QDateTime end(QDate(2012,11,15), QTime(14,00));
    Appointment appointment(start, end, "Avtalenavn", "b", "c", "d", "e");

    QDateTime start2(QDate(2012,11,15), QTime(12,00));
    Appointment appointment2(start2, start, "Tidligere avtale", "b", "c", "d", "e");

    QDate date = start.date();

    QList<Appointment> list1;
    list1 << appointment << appointment2;
    qSort(list1);

    map.insert(date, list1);


}

void CalendarMainWindow::on_gotoTodayButton_clicked() {
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->chosenDateLabel->setText(QDate::currentDate().toString());
}

void CalendarMainWindow::on_calendarWidget_clicked(const QDate &date) {
    ui->chosenDateLabel->setText(date.toString());

    QTableWidget* table = ui->appointmentTable;
    table->setRowCount(0);

    if (map.contains(date)) {
        QList<Appointment> liste = map.value(date);
        int count = liste.count();

        for (int i=0; i<count; i++) {
            Appointment appointment = liste.at(i);

            table->insertRow(i);
            table->setItem(i, 0, new QTableWidgetItem(appointment.getStartTime().time().toString()));
            table->setItem(i, 1, new QTableWidgetItem(appointment.getEndTime().time().toString()));
            table->setItem(i, 2, new QTableWidgetItem(appointment.getAppointmentName()));
        }
    }
}

void CalendarMainWindow::on_contactlistButton_clicked() {
    contactsgui.show();
}

void CalendarMainWindow::on_removeAppointmentButton_clicked() {
    QList<Appointment> list = ui->appointmentTable->currentItem();
}
