#include "appointmentui.h"
#include "ui_appointmentui.h"

AppointmentUi::AppointmentUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppointmentUi)
{
    ui->setupUi(this);
}

AppointmentUi::~AppointmentUi()
{
    delete ui;
}
