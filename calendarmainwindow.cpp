#include <QCloseEvent>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>

#include "appointment.h"
#include "calendarmainwindow.h"
#include "ui_calendarmainwindow.h"

CalendarMainWindow::CalendarMainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::CalendarMainWindow) {
    // Set up the gui
    ui->setupUi(this);
    isSok = false;
    contactsgui = new ContactsGui();
    appointmentUi = new AppointmentUi();
    ui->editAppointmentButton->setEnabled(false);
    ui->removeAppointmentButton->setEnabled(false);

    file = new QFile(getPathToFilename());

    setAppointmentTableHeaders();

    loadFromFile();

    updateAppointmentTable(ui->calendarWidget->selectedDate());

    connect(appointmentUi,SIGNAL(openContactsList()),this,SLOT(on_contactlistButton_clicked()));
    connect(contactsgui, SIGNAL(selectedContact(QString)), appointmentUi, SLOT(setContactLineEditText(QString)));
    connect(appointmentUi, SIGNAL(newAppointment(Appointment, int)), this, SLOT(addAppointmentFromUi(Appointment, int)));
    connect(ui->actionAddAppointment, SIGNAL(triggered()), this, SLOT(on_addAppointmentButton_clicked()));
    connect(ui->actionOpenContacts, SIGNAL(triggered()), this, SLOT(on_contactlistButton_clicked()));
    connect(ui->actionSaveAndExit, SIGNAL(triggered()), this, SLOT(on_closeButton_clicked()));
    connect(ui->actionDeleteAppointment, SIGNAL(triggered()), this, SLOT(on_removeAppointmentButton_clicked()));
    connect(ui->actionDeleteAllAppointment, SIGNAL(triggered()), this, SLOT(on_removeAllAppointmentsButton_clicked()));
    connect(ui->actionEditAppointment, SIGNAL(triggered()), this, SLOT(on_editAppointmentButton_clicked()));
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
    QDate startDate = appointment.getStartDateTime().date();

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

void CalendarMainWindow::addAppointmentFromUi(Appointment appointment, int repeat) {
    if (appointmentOverlaps(appointment)) {
        QMessageBox::information(this, "", "Denne avtalen overlapper en annen avtale.");
    }

    addAppointment(appointment);

    for (int i=0; i<repeat; i++) {
        appointment.moveDays(7);
        addAppointment(appointment);
    }
    updateAppointmentTable(QDate::currentDate());
    clearFields();
}

void CalendarMainWindow::on_addAppointmentButton_clicked() {
    appointmentUi->setupAppointmentUi();
    appointmentUi->setDateTimeEditDefaults();
    appointmentUi->show();
}


void CalendarMainWindow::on_appointmentTable_cellClicked(int row, int column) {
    Q_UNUSED(column);
    QDate selectedDate = ui->calendarWidget->selectedDate();
    if (!isSok && map.contains(selectedDate)) {
        QList<Appointment> list = map.value(selectedDate);
        Appointment currentAppointment = list.at(row);
        ui->editAppointmentButton->setEnabled(true);
        ui->removeAppointmentButton->setEnabled(true);

        ui->typeLineEdit->setText(currentAppointment.getType());
        ui->locationLineEdit->setText(currentAppointment.getLocation());
        ui->contactLineEdit->setText(currentAppointment.getContact());
        ui->infoLineEdit->setText(currentAppointment.getInfo());
    }
}

void CalendarMainWindow::on_calendarWidget_clicked(const QDate &date) {
    updateAppointmentTable(date);
    clearFields();
    isSok = false;
}

void CalendarMainWindow::on_closeButton_clicked() {
    saveToFile();
    this->close();
}

void CalendarMainWindow::on_contactlistButton_clicked() {
    contactsgui->show();
}

void CalendarMainWindow::on_editAppointmentButton_clicked() {
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QList<Appointment> list = map.take(selectedDate);
    Appointment currentAppointment = list.takeAt(ui->appointmentTable->currentRow());
    map.insert(selectedDate,list);
    appointmentUi->editAppointment(currentAppointment);
    appointmentUi->show();
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

void CalendarMainWindow::on_searchButton_clicked() {
    // Clear list and populate with results
    if (!ui->searchLineEdit->text().isEmpty()) {
        ui->appointmentTable->setRowCount(0);
        ui->chosenDateLabel->setText("Søkeresultater");

        QList<Appointment> list = find(ui->searchLineEdit->text());
        insertIntoAppointmentTable(list);
        isSok = true;
        clearFields();
    }
}

void CalendarMainWindow::on_searchLineEdit_returnPressed() {
    on_searchButton_clicked();
}


//Private methods
bool CalendarMainWindow::appointmentOverlaps(Appointment newAppointment) const {
    bool overlap = false;
    QDate startDate = newAppointment.getStartDateTime().date();

    if (map.contains(startDate)) {
        QList<Appointment> list = map.value(startDate);

        foreach (Appointment current, list) {
            overlap = (newAppointment.getStartDateTime() >= current.getStartDateTime()
                    && newAppointment.getStartDateTime() < current.getEndDateTime())
                    || (newAppointment.getEndDateTime() > current.getStartDateTime()
                    && newAppointment.getEndDateTime() <= current.getEndDateTime());

            if (overlap) {
                break;
            }
        }
    }

    return overlap;
}

QList<Appointment> CalendarMainWindow::find(QString key) const {
    QList<Appointment> resultsList;

    foreach (QList<Appointment> currentList, map) {
        foreach (Appointment appointment, currentList) {
            if (appointment.getQStringOfType(Appointment::NAME).contains(key, Qt::CaseInsensitive)
                    || appointment.getQStringOfType(Appointment::LOCATION).contains(key, Qt::CaseInsensitive)
                    || appointment.getQStringOfType(Appointment::CONTACT).contains(key, Qt::CaseInsensitive)
                    || appointment.getQStringOfType(Appointment::INFO).contains(key, Qt::CaseInsensitive)) {

                resultsList << appointment;
            }
        }
    }

    qSort(resultsList);
    return resultsList;
}

QString CalendarMainWindow::getPathToFilename() const {
    QString path = QApplication::applicationDirPath();
    path.append("/");
    path.append("appointments.txt");

    return path;
}

void CalendarMainWindow::insertIntoAppointmentTable(QList<Appointment> list) const {
    QTableWidget* table = ui->appointmentTable;

    int count = list.count();

    for (int i=0; i<count; i++) {
        Appointment appointment = list.at(i);
        table->insertRow(i);

        QTableWidgetItem* itemStart = new QTableWidgetItem(appointment.getStartDateTime().toString("HH:mm"));
        QTableWidgetItem* itemEnd = new QTableWidgetItem(appointment.getEndDateTime().toString("dd.MM.yy HH:mm"));
        QTableWidgetItem* itemName = new QTableWidgetItem(appointment.getAppointmentName());

        itemStart->setFlags(itemStart->flags() ^ Qt::ItemIsEditable);
        itemEnd->setFlags(itemEnd->flags() ^ Qt::ItemIsEditable);
        itemName->setFlags(itemName->flags() ^ Qt::ItemIsEditable);

        table->setItem(i, 0, itemStart);
        table->setItem(i, 1, itemEnd);
        table->setItem(i, 2, itemName);
    }
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
    ui->appointmentTable->setRowCount(0);

    if (map.contains(date)) {
        insertIntoAppointmentTable(map.value(date));
    }
}

// Required to prevent unwanted bugs after doing certain actions
void CalendarMainWindow::clearFields()
{
    ui->editAppointmentButton->setEnabled(false);
    ui->removeAppointmentButton->setEnabled(false);
    ui->typeLineEdit->setText("");
    ui->locationLineEdit->setText("");
    ui->contactLineEdit->setText("");
    ui->infoLineEdit->setText("");
}
