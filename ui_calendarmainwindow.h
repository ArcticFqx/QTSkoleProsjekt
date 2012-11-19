/********************************************************************************
** Form generated from reading UI file 'calendarmainwindow.ui'
**
** Created: Mon 19. Nov 02:05:26 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARMAINWINDOW_H
#define UI_CALENDARMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarMainWindow
{
public:
    QAction *actionSaveAndExit;
    QAction *actionAddAppointment;
    QAction *actionOpenContacts;
    QAction *actionEditAppointment;
    QAction *actionDeleteAllAppointment;
    QAction *actionDeleteAppointment;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *gotoTodayButton;
    QPushButton *contactlistButton;
    QPushButton *addAppointmentButton;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *typeLabel;
    QLineEdit *typeLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *locationLabel;
    QLineEdit *locationLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *contactLabel;
    QLineEdit *contactLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *infoLabel;
    QTextEdit *infoLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *editAppointmentButton;
    QPushButton *removeAppointmentButton;
    QPushButton *removeAllAppointmentsButton;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *chosenDateLabel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QTableWidget *appointmentTable;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QMenu *menuFil;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalendarMainWindow)
    {
        if (CalendarMainWindow->objectName().isEmpty())
            CalendarMainWindow->setObjectName(QString::fromUtf8("CalendarMainWindow"));
        CalendarMainWindow->resize(700, 449);
        CalendarMainWindow->setMinimumSize(QSize(700, 0));
        actionSaveAndExit = new QAction(CalendarMainWindow);
        actionSaveAndExit->setObjectName(QString::fromUtf8("actionSaveAndExit"));
        actionAddAppointment = new QAction(CalendarMainWindow);
        actionAddAppointment->setObjectName(QString::fromUtf8("actionAddAppointment"));
        actionOpenContacts = new QAction(CalendarMainWindow);
        actionOpenContacts->setObjectName(QString::fromUtf8("actionOpenContacts"));
        actionEditAppointment = new QAction(CalendarMainWindow);
        actionEditAppointment->setObjectName(QString::fromUtf8("actionEditAppointment"));
        actionDeleteAllAppointment = new QAction(CalendarMainWindow);
        actionDeleteAllAppointment->setObjectName(QString::fromUtf8("actionDeleteAllAppointment"));
        actionDeleteAppointment = new QAction(CalendarMainWindow);
        actionDeleteAppointment->setObjectName(QString::fromUtf8("actionDeleteAppointment"));
        centralwidget = new QWidget(CalendarMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);

        verticalLayout_2->addWidget(calendarWidget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        gotoTodayButton = new QPushButton(centralwidget);
        gotoTodayButton->setObjectName(QString::fromUtf8("gotoTodayButton"));

        horizontalLayout_6->addWidget(gotoTodayButton);

        contactlistButton = new QPushButton(centralwidget);
        contactlistButton->setObjectName(QString::fromUtf8("contactlistButton"));

        horizontalLayout_6->addWidget(contactlistButton);

        addAppointmentButton = new QPushButton(centralwidget);
        addAppointmentButton->setObjectName(QString::fromUtf8("addAppointmentButton"));

        horizontalLayout_6->addWidget(addAppointmentButton);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        typeLabel = new QLabel(centralwidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        horizontalLayout->addWidget(typeLabel);

        typeLineEdit = new QLineEdit(centralwidget);
        typeLineEdit->setObjectName(QString::fromUtf8("typeLineEdit"));
        typeLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(typeLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        locationLabel = new QLabel(centralwidget);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        horizontalLayout_2->addWidget(locationLabel);

        locationLineEdit = new QLineEdit(centralwidget);
        locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
        locationLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(locationLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        contactLabel = new QLabel(centralwidget);
        contactLabel->setObjectName(QString::fromUtf8("contactLabel"));

        horizontalLayout_3->addWidget(contactLabel);

        contactLineEdit = new QLineEdit(centralwidget);
        contactLineEdit->setObjectName(QString::fromUtf8("contactLineEdit"));
        contactLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(contactLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        horizontalLayout_4->addWidget(infoLabel);

        infoLineEdit = new QTextEdit(centralwidget);
        infoLineEdit->setObjectName(QString::fromUtf8("infoLineEdit"));
        infoLineEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(infoLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        editAppointmentButton = new QPushButton(centralwidget);
        editAppointmentButton->setObjectName(QString::fromUtf8("editAppointmentButton"));

        horizontalLayout_5->addWidget(editAppointmentButton);

        removeAppointmentButton = new QPushButton(centralwidget);
        removeAppointmentButton->setObjectName(QString::fromUtf8("removeAppointmentButton"));

        horizontalLayout_5->addWidget(removeAppointmentButton);

        removeAllAppointmentsButton = new QPushButton(centralwidget);
        removeAllAppointmentsButton->setObjectName(QString::fromUtf8("removeAllAppointmentsButton"));

        horizontalLayout_5->addWidget(removeAllAppointmentsButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        chosenDateLabel = new QLabel(centralwidget);
        chosenDateLabel->setObjectName(QString::fromUtf8("chosenDateLabel"));

        horizontalLayout_10->addWidget(chosenDateLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout_10->addWidget(searchLineEdit);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_10->addWidget(searchButton);


        verticalLayout_5->addLayout(horizontalLayout_10);

        appointmentTable = new QTableWidget(centralwidget);
        appointmentTable->setObjectName(QString::fromUtf8("appointmentTable"));
        appointmentTable->setSelectionMode(QAbstractItemView::SingleSelection);
        appointmentTable->setSortingEnabled(false);
        appointmentTable->setRowCount(0);
        appointmentTable->setColumnCount(0);
        appointmentTable->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(appointmentTable);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_7->addWidget(closeButton);


        verticalLayout_6->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_8);

        CalendarMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalendarMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 21));
        menuFil = new QMenu(menubar);
        menuFil->setObjectName(QString::fromUtf8("menuFil"));
        CalendarMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalendarMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CalendarMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFil->menuAction());
        menuFil->addAction(actionAddAppointment);
        menuFil->addAction(actionEditAppointment);
        menuFil->addAction(actionDeleteAppointment);
        menuFil->addAction(actionDeleteAllAppointment);
        menuFil->addSeparator();
        menuFil->addAction(actionOpenContacts);
        menuFil->addSeparator();
        menuFil->addAction(actionSaveAndExit);

        retranslateUi(CalendarMainWindow);

        QMetaObject::connectSlotsByName(CalendarMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarMainWindow)
    {
        CalendarMainWindow->setWindowTitle(QApplication::translate("CalendarMainWindow", "Qalender", 0, QApplication::UnicodeUTF8));
        actionSaveAndExit->setText(QApplication::translate("CalendarMainWindow", "Lagre og avslutt", 0, QApplication::UnicodeUTF8));
        actionAddAppointment->setText(QApplication::translate("CalendarMainWindow", "Legg til ny avtale", 0, QApplication::UnicodeUTF8));
        actionOpenContacts->setText(QApplication::translate("CalendarMainWindow", "\303\205pne kontaktliste", 0, QApplication::UnicodeUTF8));
        actionEditAppointment->setText(QApplication::translate("CalendarMainWindow", "Rediger avtale", 0, QApplication::UnicodeUTF8));
        actionDeleteAllAppointment->setText(QApplication::translate("CalendarMainWindow", "Slett dagens avtaler", 0, QApplication::UnicodeUTF8));
        actionDeleteAppointment->setText(QApplication::translate("CalendarMainWindow", "Slett avtale", 0, QApplication::UnicodeUTF8));
        gotoTodayButton->setText(QApplication::translate("CalendarMainWindow", "I dag", 0, QApplication::UnicodeUTF8));
        contactlistButton->setText(QApplication::translate("CalendarMainWindow", "Kontaktliste", 0, QApplication::UnicodeUTF8));
        addAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Legg til ny avtale", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("CalendarMainWindow", "Type", 0, QApplication::UnicodeUTF8));
        locationLabel->setText(QApplication::translate("CalendarMainWindow", "Sted", 0, QApplication::UnicodeUTF8));
        contactLabel->setText(QApplication::translate("CalendarMainWindow", "Kontakt", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QApplication::translate("CalendarMainWindow", "Info", 0, QApplication::UnicodeUTF8));
        editAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Endre avtale", 0, QApplication::UnicodeUTF8));
        removeAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Slett avtale", 0, QApplication::UnicodeUTF8));
        removeAllAppointmentsButton->setText(QApplication::translate("CalendarMainWindow", "Slett alle dagens avtaler", 0, QApplication::UnicodeUTF8));
        chosenDateLabel->setText(QApplication::translate("CalendarMainWindow", "Valgt dato", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("CalendarMainWindow", "S\303\270k", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("CalendarMainWindow", "Lagre og lukk", 0, QApplication::UnicodeUTF8));
        menuFil->setTitle(QApplication::translate("CalendarMainWindow", "Meny", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalendarMainWindow: public Ui_CalendarMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARMAINWINDOW_H
