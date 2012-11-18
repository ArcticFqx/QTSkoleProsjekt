/********************************************************************************
** Form generated from reading UI file 'appointmentui.ui'
**
** Created: Sun 18. Nov 14:16:47 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTUI_H
#define UI_APPOINTMENTUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
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
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *radioAvtale;
    QRadioButton *radioFravaer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateTimeEdit *dateTimeStart;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEnd;
    QFrame *frameGjenta;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *repeatCheckBox;
    QSpinBox *repeatSpinBox;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioUndervisning;
    QRadioButton *radioLab;
    QRadioButton *radioMote;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioAnnet;
    QLineEdit *lineEditAnnet;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEditLocation;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelContact;
    QLineEdit *lineEditContact;
    QToolButton *buttonContactsList;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *AppointmentUi)
    {
        if (AppointmentUi->objectName().isEmpty())
            AppointmentUi->setObjectName(QString::fromUtf8("AppointmentUi"));
        AppointmentUi->setWindowModality(Qt::ApplicationModal);
        AppointmentUi->resize(254, 378);
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

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        radioAvtale = new QRadioButton(AppointmentUi);
        radioAvtale->setObjectName(QString::fromUtf8("radioAvtale"));
        radioAvtale->setChecked(true);

        horizontalLayout_9->addWidget(radioAvtale);

        radioFravaer = new QRadioButton(AppointmentUi);
        radioFravaer->setObjectName(QString::fromUtf8("radioFravaer"));

        horizontalLayout_9->addWidget(radioFravaer);


        verticalLayout_2->addLayout(horizontalLayout_9);

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

        frameGjenta = new QFrame(AppointmentUi);
        frameGjenta->setObjectName(QString::fromUtf8("frameGjenta"));
        frameGjenta->setFrameShape(QFrame::StyledPanel);
        frameGjenta->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameGjenta);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        repeatCheckBox = new QCheckBox(frameGjenta);
        repeatCheckBox->setObjectName(QString::fromUtf8("repeatCheckBox"));

        horizontalLayout_8->addWidget(repeatCheckBox);

        repeatSpinBox = new QSpinBox(frameGjenta);
        repeatSpinBox->setObjectName(QString::fromUtf8("repeatSpinBox"));
        repeatSpinBox->setEnabled(false);

        horizontalLayout_8->addWidget(repeatSpinBox);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_2->addWidget(frameGjenta);

        frame_2 = new QFrame(AppointmentUi);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));

        verticalLayout_2->addWidget(frame_2);

        frame = new QFrame(AppointmentUi);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        radioUndervisning = new QRadioButton(frame);
        radioUndervisning->setObjectName(QString::fromUtf8("radioUndervisning"));
        radioUndervisning->setChecked(true);

        horizontalLayout_7->addWidget(radioUndervisning);

        radioLab = new QRadioButton(frame);
        radioLab->setObjectName(QString::fromUtf8("radioLab"));

        horizontalLayout_7->addWidget(radioLab);

        radioMote = new QRadioButton(frame);
        radioMote->setObjectName(QString::fromUtf8("radioMote"));

        horizontalLayout_7->addWidget(radioMote);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioAnnet = new QRadioButton(frame);
        radioAnnet->setObjectName(QString::fromUtf8("radioAnnet"));

        horizontalLayout->addWidget(radioAnnet);

        lineEditAnnet = new QLineEdit(frame);
        lineEditAnnet->setObjectName(QString::fromUtf8("lineEditAnnet"));
        lineEditAnnet->setEnabled(false);

        horizontalLayout->addWidget(lineEditAnnet);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(frame);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(AppointmentUi);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEditLocation = new QLineEdit(AppointmentUi);
        lineEditLocation->setObjectName(QString::fromUtf8("lineEditLocation"));

        horizontalLayout_4->addWidget(lineEditLocation);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelContact = new QLabel(AppointmentUi);
        labelContact->setObjectName(QString::fromUtf8("labelContact"));

        horizontalLayout_3->addWidget(labelContact);

        lineEditContact = new QLineEdit(AppointmentUi);
        lineEditContact->setObjectName(QString::fromUtf8("lineEditContact"));
        lineEditContact->setEnabled(false);
        lineEditContact->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditContact);

        buttonContactsList = new QToolButton(AppointmentUi);
        buttonContactsList->setObjectName(QString::fromUtf8("buttonContactsList"));

        horizontalLayout_3->addWidget(buttonContactsList);


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

        QWidget::setTabOrder(appointmentName, dateTimeStart);
        QWidget::setTabOrder(dateTimeStart, dateTimeEnd);
        QWidget::setTabOrder(dateTimeEnd, repeatCheckBox);
        QWidget::setTabOrder(repeatCheckBox, repeatSpinBox);
        QWidget::setTabOrder(repeatSpinBox, radioAvtale);
        QWidget::setTabOrder(radioAvtale, radioFravaer);
        QWidget::setTabOrder(radioFravaer, radioUndervisning);
        QWidget::setTabOrder(radioUndervisning, radioLab);
        QWidget::setTabOrder(radioLab, radioMote);
        QWidget::setTabOrder(radioMote, radioAnnet);
        QWidget::setTabOrder(radioAnnet, lineEditAnnet);
        QWidget::setTabOrder(lineEditAnnet, lineEditLocation);
        QWidget::setTabOrder(lineEditLocation, lineEditContact);
        QWidget::setTabOrder(lineEditContact, buttonContactsList);
        QWidget::setTabOrder(buttonContactsList, textEdit);
        QWidget::setTabOrder(textEdit, buttonBox);

        retranslateUi(AppointmentUi);
        QObject::connect(buttonBox, SIGNAL(rejected()), AppointmentUi, SLOT(close()));
        QObject::connect(repeatCheckBox, SIGNAL(toggled(bool)), repeatSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(AppointmentUi);
    } // setupUi

    void retranslateUi(QWidget *AppointmentUi)
    {
        AppointmentUi->setWindowTitle(QApplication::translate("AppointmentUi", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AppointmentUi", "Navn", 0, QApplication::UnicodeUTF8));
        radioAvtale->setText(QApplication::translate("AppointmentUi", "Avtale", 0, QApplication::UnicodeUTF8));
        radioFravaer->setText(QApplication::translate("AppointmentUi", "Frav\303\246r", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AppointmentUi", "Start", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AppointmentUi", "Slutt", 0, QApplication::UnicodeUTF8));
        repeatCheckBox->setText(QApplication::translate("AppointmentUi", "Gjenta i (antall uker):", 0, QApplication::UnicodeUTF8));
        radioUndervisning->setText(QApplication::translate("AppointmentUi", "Undervisning", 0, QApplication::UnicodeUTF8));
        radioLab->setText(QApplication::translate("AppointmentUi", "Laboratorium", 0, QApplication::UnicodeUTF8));
        radioMote->setText(QApplication::translate("AppointmentUi", "M\303\270te", 0, QApplication::UnicodeUTF8));
        radioAnnet->setText(QApplication::translate("AppointmentUi", "Annet", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AppointmentUi", "Sted", 0, QApplication::UnicodeUTF8));
        labelContact->setText(QApplication::translate("AppointmentUi", "Kontakter", 0, QApplication::UnicodeUTF8));
        buttonContactsList->setText(QApplication::translate("AppointmentUi", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AppointmentUi: public Ui_AppointmentUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTUI_H
