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


//Public slots
void AppointmentUi::setContactLineEditText(QString string)
{
    ui->lineEditContact->setText(string);
}

void AppointmentUi::on_buttonBox_accepted()
{
    QRadioButton* toggledButton = NULL;
    QString appointmentType;
    QString absence = ui->radioFravaer->isChecked() ? "1" : "0";
    qDebug() << absence << endl;
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


    if(modeEdit)
    {
        modeEdit = false;
    }
    else
    {
        Appointment appointment(ui->dateTimeStart->dateTime(), ui->dateTimeEnd->dateTime(),
                ui->appointmentName->text(), ui->lineEditLocation->text(),
                                absence, appointmentType,
                ui->textEdit->toPlainText(), ui->lineEditContact->text());
        qDebug() << appointment.toString();
        emit newAppointment(appointment, ui->repeatSpinBox->value());
    }
    close();
}

//Private methods
void AppointmentUi::setDateTimeEditDefaults() const {
    QTime time(QTime::currentTime().hour(), 0);
    ui->dateTimeStart->setDate(QDate::currentDate());
    ui->dateTimeStart->setTime(time);
    ui->dateTimeEnd->setDate(QDate::currentDate());
    ui->dateTimeEnd->setTime(time);
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
