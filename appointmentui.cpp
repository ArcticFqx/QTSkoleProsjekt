#include "appointment.h"
#include "appointmentui.h"
#include "ui_appointmentui.h"


AppointmentUi::AppointmentUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppointmentUi)
{
    ui->setupUi(this);
    connect(ui->buttonContactsList,SIGNAL(clicked()),this,SIGNAL(openContactsList()));
    connect(ui->radioAnnet,SIGNAL(toggled(bool)),ui->lineEditAnnet,SLOT(setEnabled(bool)));

    setDateTimeEditDefaults();
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
            ui->appointmentName->text(), ui->lineEditLocation->text(), appointmentType,
            ui->textEdit->toPlainText(), ui->lineEditContact->text());

    emit newAppointment(appointment, ui->repeatSpinBox->value());
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
