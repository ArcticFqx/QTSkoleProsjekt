/********************************************************************************
** Form generated from reading UI file 'calendarmainwindow.ui'
**
** Created: Fri 16. Nov 13:44:01 2012
**      by: Qt User Interface Compiler version 4.8.1
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarMainWindow
{
public:
    QWidget *centralwidget;
    QCalendarWidget *calendarWidget;
    QPushButton *gotoTodayButton;
    QPushButton *contactlistButton;
    QLabel *chosenDateLabel;
    QPushButton *addAppointmentButton;
    QPushButton *removeAppointmentButton;
    QPushButton *editAppointmentButton;
    QPushButton *removeAllAppointmentsButton;
    QTableWidget *appointmentTable;
    QLabel *typeLabel;
    QLabel *locationLabel;
    QLabel *contactLabel;
    QLabel *infoLabel;
    QLineEdit *typeLineEdit;
    QLineEdit *locationLineEdit;
    QLineEdit *contactLineEdit;
    QTextEdit *infoLineEdit;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalendarMainWindow)
    {
        if (CalendarMainWindow->objectName().isEmpty())
            CalendarMainWindow->setObjectName(QString::fromUtf8("CalendarMainWindow"));
        CalendarMainWindow->resize(800, 600);
        centralwidget = new QWidget(CalendarMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 60, 248, 155));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);
        gotoTodayButton = new QPushButton(centralwidget);
        gotoTodayButton->setObjectName(QString::fromUtf8("gotoTodayButton"));
        gotoTodayButton->setGeometry(QRect(60, 260, 75, 23));
        contactlistButton = new QPushButton(centralwidget);
        contactlistButton->setObjectName(QString::fromUtf8("contactlistButton"));
        contactlistButton->setGeometry(QRect(60, 300, 75, 23));
        chosenDateLabel = new QLabel(centralwidget);
        chosenDateLabel->setObjectName(QString::fromUtf8("chosenDateLabel"));
        chosenDateLabel->setGeometry(QRect(380, 40, 121, 16));
        addAppointmentButton = new QPushButton(centralwidget);
        addAppointmentButton->setObjectName(QString::fromUtf8("addAppointmentButton"));
        addAppointmentButton->setGeometry(QRect(180, 260, 91, 23));
        removeAppointmentButton = new QPushButton(centralwidget);
        removeAppointmentButton->setObjectName(QString::fromUtf8("removeAppointmentButton"));
        removeAppointmentButton->setGeometry(QRect(510, 460, 75, 23));
        editAppointmentButton = new QPushButton(centralwidget);
        editAppointmentButton->setObjectName(QString::fromUtf8("editAppointmentButton"));
        editAppointmentButton->setGeometry(QRect(420, 460, 75, 23));
        removeAllAppointmentsButton = new QPushButton(centralwidget);
        removeAllAppointmentsButton->setObjectName(QString::fromUtf8("removeAllAppointmentsButton"));
        removeAllAppointmentsButton->setGeometry(QRect(600, 460, 91, 23));
        appointmentTable = new QTableWidget(centralwidget);
        appointmentTable->setObjectName(QString::fromUtf8("appointmentTable"));
        appointmentTable->setGeometry(QRect(380, 90, 361, 151));
        appointmentTable->setSelectionMode(QAbstractItemView::SingleSelection);
        appointmentTable->setSortingEnabled(false);
        appointmentTable->setRowCount(0);
        appointmentTable->setColumnCount(0);
        appointmentTable->verticalHeader()->setVisible(false);
        typeLabel = new QLabel(centralwidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setGeometry(QRect(450, 280, 46, 13));
        locationLabel = new QLabel(centralwidget);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));
        locationLabel->setGeometry(QRect(450, 320, 46, 13));
        contactLabel = new QLabel(centralwidget);
        contactLabel->setObjectName(QString::fromUtf8("contactLabel"));
        contactLabel->setGeometry(QRect(450, 350, 46, 13));
        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(450, 380, 46, 13));
        typeLineEdit = new QLineEdit(centralwidget);
        typeLineEdit->setObjectName(QString::fromUtf8("typeLineEdit"));
        typeLineEdit->setGeometry(QRect(520, 280, 113, 20));
        typeLineEdit->setReadOnly(true);
        locationLineEdit = new QLineEdit(centralwidget);
        locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
        locationLineEdit->setGeometry(QRect(520, 310, 113, 20));
        locationLineEdit->setReadOnly(true);
        contactLineEdit = new QLineEdit(centralwidget);
        contactLineEdit->setObjectName(QString::fromUtf8("contactLineEdit"));
        contactLineEdit->setGeometry(QRect(520, 350, 113, 20));
        contactLineEdit->setReadOnly(true);
        infoLineEdit = new QTextEdit(centralwidget);
        infoLineEdit->setObjectName(QString::fromUtf8("infoLineEdit"));
        infoLineEdit->setGeometry(QRect(520, 380, 111, 64));
        infoLineEdit->setReadOnly(true);
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(180, 300, 75, 23));
        CalendarMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalendarMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        CalendarMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalendarMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CalendarMainWindow->setStatusBar(statusbar);

        retranslateUi(CalendarMainWindow);

        QMetaObject::connectSlotsByName(CalendarMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalendarMainWindow)
    {
        CalendarMainWindow->setWindowTitle(QApplication::translate("CalendarMainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        gotoTodayButton->setText(QApplication::translate("CalendarMainWindow", "I dag", 0, QApplication::UnicodeUTF8));
        contactlistButton->setText(QApplication::translate("CalendarMainWindow", "Kontaktliste", 0, QApplication::UnicodeUTF8));
        chosenDateLabel->setText(QApplication::translate("CalendarMainWindow", "Valgt dato", 0, QApplication::UnicodeUTF8));
        addAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Legg til ny avtale", 0, QApplication::UnicodeUTF8));
        removeAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Slett avtale", 0, QApplication::UnicodeUTF8));
        editAppointmentButton->setText(QApplication::translate("CalendarMainWindow", "Endre avtale", 0, QApplication::UnicodeUTF8));
        removeAllAppointmentsButton->setText(QApplication::translate("CalendarMainWindow", "Slett alle avtaler", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("CalendarMainWindow", "Type", 0, QApplication::UnicodeUTF8));
        locationLabel->setText(QApplication::translate("CalendarMainWindow", "Sted", 0, QApplication::UnicodeUTF8));
        contactLabel->setText(QApplication::translate("CalendarMainWindow", "Kontakt", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QApplication::translate("CalendarMainWindow", "Info", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("CalendarMainWindow", "Lagre og lukk", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalendarMainWindow: public Ui_CalendarMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARMAINWINDOW_H
