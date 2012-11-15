/********************************************************************************
** Form generated from reading UI file 'appointmentui.ui'
**
** Created: Thu 15. Nov 16:44:14 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTUI_H
#define UI_APPOINTMENTUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppointmentUi
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *appointmentName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateTimeEdit *dateTimeStart;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEnd;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioUndervisning;
    QRadioButton *radioButton_3;
    QRadioButton *radioMote;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioAnnet;
    QLineEdit *lineEditAnnet;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *AppointmentUi)
    {
        if (AppointmentUi->objectName().isEmpty())
            AppointmentUi->setObjectName(QString::fromUtf8("AppointmentUi"));
        AppointmentUi->resize(252, 315);
        verticalLayout_3 = new QVBoxLayout(AppointmentUi);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(AppointmentUi);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        appointmentName = new QLineEdit(AppointmentUi);
        appointmentName->setObjectName(QString::fromUtf8("appointmentName"));

        horizontalLayout_2->addWidget(appointmentName);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(AppointmentUi);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        dateTimeStart = new QDateTimeEdit(AppointmentUi);
        dateTimeStart->setObjectName(QString::fromUtf8("dateTimeStart"));

        horizontalLayout_5->addWidget(dateTimeStart);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(AppointmentUi);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        dateTimeEnd = new QDateTimeEdit(AppointmentUi);
        dateTimeEnd->setObjectName(QString::fromUtf8("dateTimeEnd"));

        horizontalLayout_6->addWidget(dateTimeEnd);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioUndervisning = new QRadioButton(AppointmentUi);
        radioUndervisning->setObjectName(QString::fromUtf8("radioUndervisning"));

        horizontalLayout_7->addWidget(radioUndervisning);

        radioButton_3 = new QRadioButton(AppointmentUi);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_7->addWidget(radioButton_3);

        radioMote = new QRadioButton(AppointmentUi);
        radioMote->setObjectName(QString::fromUtf8("radioMote"));

        horizontalLayout_7->addWidget(radioMote);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioAnnet = new QRadioButton(AppointmentUi);
        radioAnnet->setObjectName(QString::fromUtf8("radioAnnet"));

        horizontalLayout->addWidget(radioAnnet);

        lineEditAnnet = new QLineEdit(AppointmentUi);
        lineEditAnnet->setObjectName(QString::fromUtf8("lineEditAnnet"));
        lineEditAnnet->setEnabled(false);

        horizontalLayout->addWidget(lineEditAnnet);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(AppointmentUi);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_2 = new QLineEdit(AppointmentUi);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(AppointmentUi);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox = new QComboBox(AppointmentUi);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        toolButton = new QToolButton(AppointmentUi);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_3->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit = new QTextEdit(AppointmentUi);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        buttonBox = new QDialogButtonBox(AppointmentUi);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMaximumSize(QSize(16777215, 16777215));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(AppointmentUi);

        QMetaObject::connectSlotsByName(AppointmentUi);
    } // setupUi

    void retranslateUi(QWidget *AppointmentUi)
    {
        AppointmentUi->setWindowTitle(QApplication::translate("AppointmentUi", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AppointmentUi", "Navn", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AppointmentUi", "Start", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AppointmentUi", "Slutt", 0, QApplication::UnicodeUTF8));
        radioUndervisning->setText(QApplication::translate("AppointmentUi", "Undervisning", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("AppointmentUi", "Laboratorium", 0, QApplication::UnicodeUTF8));
        radioMote->setText(QApplication::translate("AppointmentUi", "M\303\270te", 0, QApplication::UnicodeUTF8));
        radioAnnet->setText(QApplication::translate("AppointmentUi", "Annet", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AppointmentUi", "Sted", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AppointmentUi", "Kontakter", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("AppointmentUi", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AppointmentUi: public Ui_AppointmentUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTUI_H
