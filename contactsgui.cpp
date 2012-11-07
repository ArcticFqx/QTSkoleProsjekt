#include <QAction>

#include "contactaddgui.h"
#include "contactsgui.h"
#include "ui_contactsgui.h"

ContactsGui::ContactsGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactsGui)
{
    ui->setupUi(this);
    addGui = new ContactAddGui();
    dummyData();
}

ContactsGui::~ContactsGui()
{
    delete ui;
}


void ContactsGui::dummyData() {
    ui->contactsList->addItem("Sveinung");
    ui->contactsList->addItem("Dan-Eric");
    ui->contactsList->addItem("Erling");
}

void ContactsGui::on_addButton_clicked() {
    addGui->show();
    ui->contactsList->addItem("trykte på knapp");
}
