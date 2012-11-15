#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QTextStream>

#include "contactsgui.h"
#include "ui_contactsgui.h"


ContactsGui::ContactsGui(QWidget *parent) : QWidget(parent), ui(new Ui::ContactsGui) {
    ui->setupUi(this);

    file = new QFile(getPathToFilename());
    readFromFile();
}

ContactsGui::~ContactsGui() {
    delete ui;
}


//Private slots
void ContactsGui::on_addButton_clicked() {
    bool ok;
    QString contact = QInputDialog::getText(this, "Ny kontakt", "Navn:", QLineEdit::Normal, "", &ok);

    if (ok && !contact.isEmpty()) {
        ui->contactsList->addItem(contact);
    }
}

void ContactsGui::on_closeButton_clicked() {
    saveToFile();
    emit selectedContact(ui->contactsList->currentItem()->text());
}

void ContactsGui::on_deleteButton_clicked() {
    delete ui->contactsList->currentItem();
}


//Private methods
QString ContactsGui::getPathToFilename() const {
    QString path = QApplication::applicationDirPath();
    path.append("/");
    path.append("contacts.txt");

    return path;
}

void ContactsGui::readFromFile() const {
    if (!file->open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file." << endl;
    } else {
        QTextStream in(file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            ui->contactsList->addItem(line);
        }
    }

    file->close();
}

void ContactsGui::saveToFile() const {
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(file);
    int count = ui->contactsList->count();

    for (int i=0; i<count; i++) {
        QString item = ui->contactsList->item(i)->text();
        out << item << endl;
    }

    file->close();
}
