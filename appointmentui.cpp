#include "appointmentui.h"
#include "ui_appointmentui.h"

AppointmentUi::AppointmentUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AppointmentUi)
{
    ui->setupUi(this);
    connect(ui->buttonContactsList,SIGNAL(clicked()),this,SLOT(triggerOpenContactsList()));
    connect(ui->radioAnnet,SIGNAL(toggled(bool)),ui->lineEditAnnet,SLOT(setEnabled(bool)));
}

AppointmentUi::~AppointmentUi()
{
    delete ui;
}

void AppointmentUi::triggerOpenContactsList()
{
    emit openContactsList();
}
