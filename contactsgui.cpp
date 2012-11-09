#include <QAction>
#include <QInputDialog>
#include <QLineEdit>

#include "contactsgui.h"
#include "ui_contactsgui.h"


ContactsGui::ContactsGui(QWidget *parent) : QWidget(parent), ui(new Ui::ContactsGui) {
    ui->setupUi(this);
    dummyData();
}

ContactsGui::~ContactsGui() {
    delete ui;
}


void ContactsGui::dummyData() {
    ui->contactsList->addItem("Sveinung");
    ui->contactsList->addItem("Dan-Eric");
    ui->contactsList->addItem("Erling");
}

void ContactsGui::on_addButton_clicked() {
    bool ok;
    QString contact = QInputDialog::getText(this, "Ny kontakt", "Navn:", QLineEdit::Normal, "", &ok);

    if (ok && !contact.isEmpty()) {
        ui->contactsList->addItem(contact);
    }
}

void ContactsGui::on_deleteButton_clicked() {
    delete ui->contactsList->currentItem();
}
