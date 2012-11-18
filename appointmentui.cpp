#include "appointment.h"
#include "appointmentui.h"
#include "ui_appointmentui.h"
#include "QDebug"

AppointmentUi::AppointmentUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppointmentUi)
{
    ui->setupUi(this);
    connect(ui->buttonContactsList,SIGNAL(clicked()),this,SIGNAL(openContactsList()));
    connect(ui->radioAnnet,SIGNAL(toggled(bool)),ui->lineEditAnnet,SLOT(setEnabled(bool)));

    setDateTimeEditDefaults();
    modeEdit = false;
}

AppointmentUi::~AppointmentUi()
{
    delete ui;
}


//Public methods
void AppointmentUi::setDateTimeEditDefaults() const {
    QTime time(QTime::currentTime().hour(), 0);
    ui->dateTimeStart->setDate(QDate::currentDate());
    ui->dateTimeStart->setTime(time);
    ui->dateTimeEnd->setDate(QDate::currentDate());
    ui->dateTimeEnd->setTime(time);
}


//Public slots
void AppointmentUi::setContactLineEditText(QString string)
{
    ui->lineEditContact->setText(string);
}


//Private slots
void AppointmentUi::on_buttonBox_accepted()
{
    QRadioButton* toggledButton = NULL;
    QString appointmentType;
    QString absence = ui->radioFravaer->isChecked() ? "1" : "0";
    QString misc = ui->radioAnnet->isChecked() ? "1" : "0";

    if (ui->radioUndervisning->isChecked()) {
        toggledButton = ui->radioUndervisning;
    } else if (ui->radioMote->isChecked()) {
        toggledButton = ui->radioMote;
    } else if (ui->radioLab->isChecked()) {
        toggledButton = ui->radioLab;
    }

    if (toggledButton != NULL) {
        appointmentType = toggledButton->text();
    } else {
        appointmentType = ui->lineEditAnnet->text();
    }

    Appointment appointment(ui->dateTimeStart->dateTime(), ui->dateTimeEnd->dateTime(),
            ui->appointmentName->text(), ui->lineEditLocation->text(),
                            absence, misc, appointmentType,
            ui->textEdit->toPlainText(), ui->lineEditContact->text());

    if(modeEdit) {
        //emit newAppointment(appointment, repeat);
        modeEdit = false;
    } else {
        int repeat = ui->repeatCheckBox->isChecked() ? ui->repeatSpinBox->value() : 0;
        emit newAppointment(appointment, repeat);
    }
    close();
}

void AppointmentUi::on_dateTimeStart_dateTimeChanged(const QDateTime &date) {
    ui->dateTimeEnd->setMinimumDateTime(date);
}

void AppointmentUi::setupAppointmentUi()
{
    setWindowTitle("Ny avtale");
    ui->appointmentName->setText("");
    ui->radioAvtale->setChecked(true);
    ui->radioUndervisning->setChecked(true);
    ui->lineEditLocation->setText("");
    ui->lineEditContact->setText("");
    ui->lineEditAnnet->setText("");
}

void AppointmentUi::editAppointment(Appointment currentAppointment)
{
    modeEdit = true;
    ui->appointmentName->setText(currentAppointment.getAppointmentName());
    ui->radioFravaer->setChecked(currentAppointment.getAbsence()=="1" ? true : false);
    ui->dateTimeStart->setDateTime(currentAppointment.getStartDateTime());
    ui->dateTimeEnd->setDateTime(currentAppointment.getEndDateTime());
    ui->lineEditLocation->setText(currentAppointment.getLocation());
    ui->lineEditContact->setText(currentAppointment.getContact());
    ui->textEdit->setText(currentAppointment.getInfo());

    if (currentAppointment.getMisc() == "0")
    {
        QString type = currentAppointment.getType();
        if(type == "Undervisning" || type == "Ferie" ){
            ui->radioUndervisning->setChecked(true);
        } else if(type == "Laboratorium" || type == "Avspasering"){
            ui->radioLab->setChecked(true);
        } else if(type == "Møte" || type == "Kurs"){
            ui->radioMote->setChecked(true);
        }
    } else {
        ui->radioAnnet->setChecked(true);
        ui->lineEditAnnet->setText(currentAppointment.getType());
    }
}

void AppointmentUi::on_radioAvtale_toggled(bool checked)
{
    if(checked)
    {
        ui->frameGjenta->show();
        setWindowTitle("Ny avtale");
        ui->radioUndervisning->setText("Undervisning");
        ui->radioLab->setText("Laboratorium");
        ui->radioMote->setText("Møte");
    }
    else
    {
        ui->frameGjenta->hide();
        setWindowTitle("Legg til fravær");
        ui->radioUndervisning->setText("Ferie");
        ui->radioLab->setText("Avspasering");
        ui->radioMote->setText("Kurs");
    }
}
