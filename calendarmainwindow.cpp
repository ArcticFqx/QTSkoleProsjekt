#include <iostream>
#include <QCloseEvent>
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
    contactsgui = new ContactsGui();
    appointmentUi = new AppointmentUi();

    file = new QFile(getPathToFilename());

    setAppointmentTableHeaders();


    loadFromFile();


    updateAppointmentTable(ui->calendarWidget->selectedDate());

    connect(appointmentUi,SIGNAL(openContactsList()),this,SLOT(on_contactlistButton_clicked()));
    connect(contactsgui, SIGNAL(selectedContact(QString)), appointmentUi, SLOT(setContactLineEditText(QString)));
    connect(appointmentUi, SIGNAL(newAppointment(Appointment, int)), this, SLOT(addAppointment(Appointment, int)));
    connect(ui->actionAddAppointment, SIGNAL(triggered()), this, SLOT(on_addAppointmentButton_clicked()));
    connect(ui->actionOpenContacts, SIGNAL(triggered()), this, SLOT(on_contactlistButton_clicked()));
    connect(ui->actionSaveAndExit, SIGNAL(triggered()), this, SLOT(on_closeButton_clicked()));
    connect(ui->actionDeleteAppointment, SIGNAL(triggered()), this, SLOT(on_removeAppointmentButton_clicked()));
    connect(ui->actionDeleteAllAppointment, SIGNAL(triggered()), this, SLOT(on_removeAllAppointmentsButton_clicked()));


}

CalendarMainWindow::~CalendarMainWindow() {
    delete contactsgui;
    delete appointmentUi;
    delete ui;
}


//Public methods
void CalendarMainWindow::closeEvent(QCloseEvent* event) {
    saveToFile();
    event->accept();
}

//Private slots
void CalendarMainWindow::addAppointment(Appointment appointment) {
    QDate startDate = appointment.getStartTime().date();

    if (map.contains(startDate)) {
        QList<Appointment> list = map.take(startDate);
        list << appointment;
        qSort(list);
        map.insert(startDate, list);
    } else {
        QList<Appointment> list;
        list << appointment;
        map.insert(startDate, list);
    }
}

void CalendarMainWindow::addAppointment(Appointment appointment, int repeat) {
    addAppointment(appointment);

    for (int i=0; i<repeat; i++) {
        appointment.moveDays(7);
        addAppointment(appointment);
    }
}

void CalendarMainWindow::on_addAppointmentButton_clicked() {
    appointmentUi->show();
}

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
    contactsgui->show();
}

void CalendarMainWindow::on_gotoTodayButton_clicked() {
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    updateAppointmentTable(QDate::currentDate());
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

void CalendarMainWindow::loadFromFile() {
    if (!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file." << endl;
    } else {
        QTextStream in(file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(Appointment::SEPARATOR);

            Appointment appointment(fields);
            addAppointment(appointment);
        }
    }

    file->close();
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
