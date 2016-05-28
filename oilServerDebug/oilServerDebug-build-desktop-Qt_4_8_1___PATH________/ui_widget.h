/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sun May 31 09:13:47 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *IPlineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLineEdit *COMlineEdit;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLineEdit *clientIPlineEdit;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QLineEdit *clientComlineEdit;
    QPushButton *connectpushButton;
    QPushButton *photopushButton;
    QPushButton *clearDatapushButton;
    QPushButton *clearphotopushButton;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QTextBrowser *picturetextBrowser;
    QLabel *picturelabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(578, 517);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        IPlineEdit = new QLineEdit(Widget);
        IPlineEdit->setObjectName(QString::fromUtf8("IPlineEdit"));

        verticalLayout_2->addWidget(IPlineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        COMlineEdit = new QLineEdit(Widget);
        COMlineEdit->setObjectName(QString::fromUtf8("COMlineEdit"));

        verticalLayout_3->addWidget(COMlineEdit);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        clientIPlineEdit = new QLineEdit(Widget);
        clientIPlineEdit->setObjectName(QString::fromUtf8("clientIPlineEdit"));

        verticalLayout_4->addWidget(clientIPlineEdit);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_5->addWidget(label_4);

        clientComlineEdit = new QLineEdit(Widget);
        clientComlineEdit->setObjectName(QString::fromUtf8("clientComlineEdit"));

        verticalLayout_5->addWidget(clientComlineEdit);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 2, 1);

        connectpushButton = new QPushButton(Widget);
        connectpushButton->setObjectName(QString::fromUtf8("connectpushButton"));

        gridLayout->addWidget(connectpushButton, 0, 1, 1, 1);

        photopushButton = new QPushButton(Widget);
        photopushButton->setObjectName(QString::fromUtf8("photopushButton"));

        gridLayout->addWidget(photopushButton, 0, 2, 1, 1);

        clearDatapushButton = new QPushButton(Widget);
        clearDatapushButton->setObjectName(QString::fromUtf8("clearDatapushButton"));

        gridLayout->addWidget(clearDatapushButton, 1, 1, 1, 1);

        clearphotopushButton = new QPushButton(Widget);
        clearphotopushButton->setObjectName(QString::fromUtf8("clearphotopushButton"));

        gridLayout->addWidget(clearphotopushButton, 1, 2, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_7->addWidget(label_5);

        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_7->addWidget(textBrowser);


        gridLayout->addLayout(verticalLayout_7, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        picturetextBrowser = new QTextBrowser(Widget);
        picturetextBrowser->setObjectName(QString::fromUtf8("picturetextBrowser"));

        verticalLayout->addWidget(picturetextBrowser);

        picturelabel = new QLabel(Widget);
        picturelabel->setObjectName(QString::fromUtf8("picturelabel"));

        verticalLayout->addWidget(picturelabel);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);

        gridLayout->addLayout(verticalLayout, 2, 1, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250IP</p></body></html>", 0, QApplication::UnicodeUTF8));
        IPlineEdit->setText(QApplication::translate("Widget", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243</p></body></html>", 0, QApplication::UnicodeUTF8));
        COMlineEdit->setText(QApplication::translate("Widget", "30001", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\256\242\346\210\267\347\253\257IP</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\256\242\346\210\267\347\253\257\347\253\257\345\217\243</p></body></html>", 0, QApplication::UnicodeUTF8));
        connectpushButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        photopushButton->setText(QApplication::translate("Widget", "\346\213\215\347\205\247", 0, QApplication::UnicodeUTF8));
        clearDatapushButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        clearphotopushButton->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\347\205\247\347\211\207", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\277\241\346\201\257\346\230\276\347\244\272\346\240\217", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\347\205\247\347\211\207\344\277\241\346\201\257\346\230\276\347\244\272\346\240\217", 0, QApplication::UnicodeUTF8));
        picturelabel->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:600; vertical-align:super;\">wait for picture</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
