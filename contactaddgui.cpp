#include "contactaddgui.h"
#include "ui_contactaddgui.h"

ContactAddGui::ContactAddGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactAddGui)
{
    ui->setupUi(this);
}

ContactAddGui::~ContactAddGui()
{
    delete ui;
}
