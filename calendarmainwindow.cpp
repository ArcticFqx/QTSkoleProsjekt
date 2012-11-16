#include <iostream>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>

#include "appointment.h"
#include "calendarmainwindow.h"
#include "ui_calendarmainwindow.h"


CalendarMainWindow::CalendarMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CalendarMainWindow) {

    ui->setupUi(this);
    setAppointmentTableHeaders();
    file = new QFile(getPathToFilename());

    load();
    updateAppointmentTable(ui->calendarWidget->selectedDate());
}

CalendarMainWindow::~CalendarMainWindow() {
    delete ui;
}


//Private slots
void CalendarMainWindow::on_appointmentTable_cellClicked(int row, int column) {
    QDate selectedDate = ui->calendarWidget->selectedDate();

    if (map.contains(selectedDate)) {
        QList<Appointment> list = map.value(selectedDate);
        Appointment appointment = list.at(row);

        ui->typeLineEdit->setText(appointment.getType());
        ui->locationLineEdit->setText(appointment.getLocation());
        ui->contactLineEdit->setText(appointment.getContact());
        ui->infoLineEdit->setText(appointment.getInfo());
    }
}

void CalendarMainWindow::on_calendarWidget_clicked(const QDate &date) {
    updateAppointmentTable(date);
}

void CalendarMainWindow::on_closeButton_clicked() {
    saveToFile();
    this->close();
}

void CalendarMainWindow::on_contactlistButton_clicked() {
    contactsgui.show();
}

void CalendarMainWindow::on_gotoTodayButton_clicked() {
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->chosenDateLabel->setText(QDate::currentDate().toString());
}

void CalendarMainWindow::on_removeAllAppointmentsButton_clicked() {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    map.remove(selectedDate);
    updateAppointmentTable(selectedDate);
}

void CalendarMainWindow::on_removeAppointmentButton_clicked() {
    int row = ui->appointmentTable->currentRow();
    QDate selectedDate = ui->calendarWidget->selectedDate();

    if (map.contains(selectedDate)) {
        QList<Appointment> list = map.take(selectedDate);
        list.removeAt(row);
        map.insert(selectedDate, list);

        updateAppointmentTable(selectedDate);
    }
}


//Private methods
QString CalendarMainWindow::getPathToFilename() const {
    QString path = QApplication::applicationDirPath();
    path.append("/");
    path.append("appointments.txt");

    return path;
}

void CalendarMainWindow::load() {
    QDateTime start(QDate(2012,11,15), QTime(13,00));
    QDateTime end(QDate(2012,11,15), QTime(14,00));
    Appointment appointment(start, end, "Avtalenavn", "Bergen", "Undervisning", "Forelesning med Seip", "Petter Seip");

    QDateTime start2(QDate(2012,11,15), QTime(12,00));
    Appointment appointment2(start2, start, "Tidligere avtale", "Oslo", "Møte", "Snakka litt", "Random Fyr");

    QDate date = start.date();

    QList<Appointment> list1;
    list1 << appointment << appointment2;
    qSort(list1);

    map.insert(date, list1);
}

void CalendarMainWindow::saveToFile() const {
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(file);

    foreach (QList<Appointment> list, map) {
        foreach (Appointment appointment, list) {
            out << appointment.toString() << endl;
        }
    }

    file->close();
}

void CalendarMainWindow::setAppointmentTableHeaders() const {
    QTableWidget* table = ui->appointmentTable;
    QStringList headerLabels;
    headerLabels << "Starttid" << "Sluttid" << "Navn";

    table->setColumnCount(headerLabels.count());
    table->setHorizontalHeaderLabels(headerLabels);
    table->horizontalHeader()->setResizeMode(0, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setResizeMode(1, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);
}

void CalendarMainWindow::updateAppointmentTable(const QDate& date) const {
    ui->chosenDateLabel->setText(date.toString("dd.MM.yyyy"));

    QTableWidget* table = ui->appointmentTable;
    table->setRowCount(0);

    if (map.contains(date)) {
        QList<Appointment> list = map.value(date);
        int count = list.count();

        for (int i=0; i<count; i++) {
            Appointment appointment = list.at(i);
            table->insertRow(i);

            QTableWidgetItem* itemStart = new QTableWidgetItem(appointment.getStartTime().toString("HH:mm"));
            QTableWidgetItem* itemEnd = new QTableWidgetItem(appointment.getEndTime().toString("dd.MM.yy HH:mm"));
            QTableWidgetItem* itemName = new QTableWidgetItem(appointment.getAppointmentName());

            itemStart->setFlags(itemStart->flags() ^ Qt::ItemIsEditable);
            itemEnd->setFlags(itemEnd->flags() ^ Qt::ItemIsEditable);
            itemName->setFlags(itemName->flags() ^ Qt::ItemIsEditable);

            table->setItem(i, 0, itemStart);
            table->setItem(i, 1, itemEnd);
            table->setItem(i, 2, itemName);
        }
    }
}
