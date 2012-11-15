/********************************************************************************
** Form generated from reading UI file 'contactsgui.ui'
**
** Created: Thu 15. Nov 16:41:48 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTSGUI_H
#define UI_CONTACTSGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactsGui
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QListWidget *contactsList;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *closeButton;

    void setupUi(QWidget *ContactsGui)
    {
        if (ContactsGui->objectName().isEmpty())
            ContactsGui->setObjectName(QString::fromUtf8("ContactsGui"));
        ContactsGui->resize(400, 300);
        layoutWidget = new QWidget(ContactsGui);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 351, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        contactsList = new QListWidget(layoutWidget);
        contactsList->setObjectName(QString::fromUtf8("contactsList"));
        contactsList->setSortingEnabled(true);

        gridLayout->addWidget(contactsList, 1, 0, 1, 3);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 2, 0, 1, 1);

        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 2, 1, 1, 1);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout->addWidget(closeButton, 2, 2, 1, 1);


        retranslateUi(ContactsGui);
        QObject::connect(closeButton, SIGNAL(clicked()), ContactsGui, SLOT(close()));

        QMetaObject::connectSlotsByName(ContactsGui);
    } // setupUi

    void retranslateUi(QWidget *ContactsGui)
    {
        ContactsGui->setWindowTitle(QApplication::translate("ContactsGui", "Kontaktliste", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ContactsGui", "Kontakter", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("ContactsGui", "Opprett ny", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("ContactsGui", "Slett", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("ContactsGui", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactsGui: public Ui_ContactsGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTSGUI_H
