/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Jun 3 11:53:50 2015
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
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_3;
    QLineEdit *IPLineEdit;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_4;
    QLineEdit *comLineEdit;
    QVBoxLayout *verticalLayout_17;
    QPushButton *connectpushButton;
    QComboBox *funComboBox;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLineEdit *preAddr1lineEdit;
    QLineEdit *preAddr2lineEdit;
    QLineEdit *preAddr3lineEdit;
    QLineEdit *preAddr4lineEdit;
    QLineEdit *preAddr5lineEdit;
    QLineEdit *preAddr6lineEdit;
    QLineEdit *preAddr7lineEdit;
    QLineEdit *preAddr8lineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLineEdit *preAddr9lineEdit;
    QLineEdit *preAddr10lineEdit;
    QLineEdit *preAddr11lineEdit;
    QLineEdit *preAddr12lineEdit;
    QLineEdit *preAddr13lineEdit;
    QLineEdit *lpreAddr14lineEdit;
    QLineEdit *preAddr15lineEdit;
    QLineEdit *preAddr16lineEdit;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *readPushButton;
    QPushButton *modiPushButton;
    QPushButton *confPushButton;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_12;
    QLineEdit *blocAddr1lineEdit;
    QLineEdit *blocAddr2lineEdit;
    QLineEdit *blocAddr3lineEdit;
    QLineEdit *blocAddr4lineEdit;
    QVBoxLayout *verticalLayout_13;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_13;
    QLineEdit *blocAddr5lineEdit;
    QLineEdit *blocAddr6lineEdit;
    QLineEdit *blocAddr7lineEdit;
    QLineEdit *blocAddr8lineEdit;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QLineEdit *flowAddr1lineEdit;
    QLineEdit *flowType1lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *flowAddr2lineEdit;
    QLineEdit *flowType2lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *flowAddr3lineEdit;
    QLineEdit *flowType3lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *flowAddr4lineEdit;
    QLineEdit *flowType4lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *flowAddr5lineEdit;
    QLineEdit *flowType5lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *flowAddr6lineEdit;
    QLineEdit *flowType6lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *flowAddr7lineEdit;
    QLineEdit *flowType7lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *flowAddr8lineEdit;
    QLineEdit *flowType8lineEdit;
    QLabel *picturelabel;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLineEdit *severIPLineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLineEdit *severComLineEdit;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QLineEdit *preNumLineEdit;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QLineEdit *flowNumLineEdit;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QLineEdit *bloNumLineEdit;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_14;
    QLineEdit *devidLineEdit;
    QVBoxLayout *verticalLayout_18;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1111, 683);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_11->addWidget(label_3);

        IPLineEdit = new QLineEdit(Widget);
        IPLineEdit->setObjectName(QString::fromUtf8("IPLineEdit"));

        verticalLayout_11->addWidget(IPLineEdit);


        horizontalLayout_11->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_12->addWidget(label_4);

        comLineEdit = new QLineEdit(Widget);
        comLineEdit->setObjectName(QString::fromUtf8("comLineEdit"));

        verticalLayout_12->addWidget(comLineEdit);


        horizontalLayout_11->addLayout(verticalLayout_12);

        horizontalLayout_11->setStretch(0, 2);
        horizontalLayout_11->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        connectpushButton = new QPushButton(Widget);
        connectpushButton->setObjectName(QString::fromUtf8("connectpushButton"));

        verticalLayout_17->addWidget(connectpushButton);

        funComboBox = new QComboBox(Widget);
        funComboBox->setObjectName(QString::fromUtf8("funComboBox"));

        verticalLayout_17->addWidget(funComboBox);


        gridLayout->addLayout(verticalLayout_17, 0, 1, 1, 1);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        preAddr1lineEdit = new QLineEdit(Widget);
        preAddr1lineEdit->setObjectName(QString::fromUtf8("preAddr1lineEdit"));

        verticalLayout_2->addWidget(preAddr1lineEdit);

        preAddr2lineEdit = new QLineEdit(Widget);
        preAddr2lineEdit->setObjectName(QString::fromUtf8("preAddr2lineEdit"));

        verticalLayout_2->addWidget(preAddr2lineEdit);

        preAddr3lineEdit = new QLineEdit(Widget);
        preAddr3lineEdit->setObjectName(QString::fromUtf8("preAddr3lineEdit"));

        verticalLayout_2->addWidget(preAddr3lineEdit);

        preAddr4lineEdit = new QLineEdit(Widget);
        preAddr4lineEdit->setObjectName(QString::fromUtf8("preAddr4lineEdit"));

        verticalLayout_2->addWidget(preAddr4lineEdit);

        preAddr5lineEdit = new QLineEdit(Widget);
        preAddr5lineEdit->setObjectName(QString::fromUtf8("preAddr5lineEdit"));

        verticalLayout_2->addWidget(preAddr5lineEdit);

        preAddr6lineEdit = new QLineEdit(Widget);
        preAddr6lineEdit->setObjectName(QString::fromUtf8("preAddr6lineEdit"));

        verticalLayout_2->addWidget(preAddr6lineEdit);

        preAddr7lineEdit = new QLineEdit(Widget);
        preAddr7lineEdit->setObjectName(QString::fromUtf8("preAddr7lineEdit"));

        verticalLayout_2->addWidget(preAddr7lineEdit);

        preAddr8lineEdit = new QLineEdit(Widget);
        preAddr8lineEdit->setObjectName(QString::fromUtf8("preAddr8lineEdit"));

        verticalLayout_2->addWidget(preAddr8lineEdit);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_3->addWidget(label_9);

        preAddr9lineEdit = new QLineEdit(Widget);
        preAddr9lineEdit->setObjectName(QString::fromUtf8("preAddr9lineEdit"));

        verticalLayout_3->addWidget(preAddr9lineEdit);

        preAddr10lineEdit = new QLineEdit(Widget);
        preAddr10lineEdit->setObjectName(QString::fromUtf8("preAddr10lineEdit"));

        verticalLayout_3->addWidget(preAddr10lineEdit);

        preAddr11lineEdit = new QLineEdit(Widget);
        preAddr11lineEdit->setObjectName(QString::fromUtf8("preAddr11lineEdit"));

        verticalLayout_3->addWidget(preAddr11lineEdit);

        preAddr12lineEdit = new QLineEdit(Widget);
        preAddr12lineEdit->setObjectName(QString::fromUtf8("preAddr12lineEdit"));

        verticalLayout_3->addWidget(preAddr12lineEdit);

        preAddr13lineEdit = new QLineEdit(Widget);
        preAddr13lineEdit->setObjectName(QString::fromUtf8("preAddr13lineEdit"));

        verticalLayout_3->addWidget(preAddr13lineEdit);

        lpreAddr14lineEdit = new QLineEdit(Widget);
        lpreAddr14lineEdit->setObjectName(QString::fromUtf8("lpreAddr14lineEdit"));

        verticalLayout_3->addWidget(lpreAddr14lineEdit);

        preAddr15lineEdit = new QLineEdit(Widget);
        preAddr15lineEdit->setObjectName(QString::fromUtf8("preAddr15lineEdit"));

        verticalLayout_3->addWidget(preAddr15lineEdit);

        preAddr16lineEdit = new QLineEdit(Widget);
        preAddr16lineEdit->setObjectName(QString::fromUtf8("preAddr16lineEdit"));

        verticalLayout_3->addWidget(preAddr16lineEdit);


        horizontalLayout_9->addLayout(verticalLayout_3);


        verticalLayout_15->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        readPushButton = new QPushButton(Widget);
        readPushButton->setObjectName(QString::fromUtf8("readPushButton"));

        verticalLayout_4->addWidget(readPushButton);

        modiPushButton = new QPushButton(Widget);
        modiPushButton->setObjectName(QString::fromUtf8("modiPushButton"));

        verticalLayout_4->addWidget(modiPushButton);

        confPushButton = new QPushButton(Widget);
        confPushButton->setObjectName(QString::fromUtf8("confPushButton"));

        verticalLayout_4->addWidget(confPushButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12);

        blocAddr1lineEdit = new QLineEdit(Widget);
        blocAddr1lineEdit->setObjectName(QString::fromUtf8("blocAddr1lineEdit"));

        verticalLayout_4->addWidget(blocAddr1lineEdit);

        blocAddr2lineEdit = new QLineEdit(Widget);
        blocAddr2lineEdit->setObjectName(QString::fromUtf8("blocAddr2lineEdit"));

        verticalLayout_4->addWidget(blocAddr2lineEdit);

        blocAddr3lineEdit = new QLineEdit(Widget);
        blocAddr3lineEdit->setObjectName(QString::fromUtf8("blocAddr3lineEdit"));

        verticalLayout_4->addWidget(blocAddr3lineEdit);

        blocAddr4lineEdit = new QLineEdit(Widget);
        blocAddr4lineEdit->setObjectName(QString::fromUtf8("blocAddr4lineEdit"));

        verticalLayout_4->addWidget(blocAddr4lineEdit);


        horizontalLayout_12->addLayout(verticalLayout_4);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_13->addWidget(plainTextEdit);

        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_13->addWidget(label_13);

        blocAddr5lineEdit = new QLineEdit(Widget);
        blocAddr5lineEdit->setObjectName(QString::fromUtf8("blocAddr5lineEdit"));

        verticalLayout_13->addWidget(blocAddr5lineEdit);

        blocAddr6lineEdit = new QLineEdit(Widget);
        blocAddr6lineEdit->setObjectName(QString::fromUtf8("blocAddr6lineEdit"));

        verticalLayout_13->addWidget(blocAddr6lineEdit);

        blocAddr7lineEdit = new QLineEdit(Widget);
        blocAddr7lineEdit->setObjectName(QString::fromUtf8("blocAddr7lineEdit"));

        verticalLayout_13->addWidget(blocAddr7lineEdit);

        blocAddr8lineEdit = new QLineEdit(Widget);
        blocAddr8lineEdit->setObjectName(QString::fromUtf8("blocAddr8lineEdit"));

        verticalLayout_13->addWidget(blocAddr8lineEdit);


        horizontalLayout_12->addLayout(verticalLayout_13);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);

        verticalLayout_15->addLayout(horizontalLayout_12);


        gridLayout->addLayout(verticalLayout_15, 0, 2, 2, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_10->addWidget(label_10);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        flowAddr1lineEdit = new QLineEdit(Widget);
        flowAddr1lineEdit->setObjectName(QString::fromUtf8("flowAddr1lineEdit"));

        horizontalLayout->addWidget(flowAddr1lineEdit);

        flowType1lineEdit = new QLineEdit(Widget);
        flowType1lineEdit->setObjectName(QString::fromUtf8("flowType1lineEdit"));

        horizontalLayout->addWidget(flowType1lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        flowAddr2lineEdit = new QLineEdit(Widget);
        flowAddr2lineEdit->setObjectName(QString::fromUtf8("flowAddr2lineEdit"));

        horizontalLayout_2->addWidget(flowAddr2lineEdit);

        flowType2lineEdit = new QLineEdit(Widget);
        flowType2lineEdit->setObjectName(QString::fromUtf8("flowType2lineEdit"));

        horizontalLayout_2->addWidget(flowType2lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        flowAddr3lineEdit = new QLineEdit(Widget);
        flowAddr3lineEdit->setObjectName(QString::fromUtf8("flowAddr3lineEdit"));

        horizontalLayout_3->addWidget(flowAddr3lineEdit);

        flowType3lineEdit = new QLineEdit(Widget);
        flowType3lineEdit->setObjectName(QString::fromUtf8("flowType3lineEdit"));

        horizontalLayout_3->addWidget(flowType3lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        flowAddr4lineEdit = new QLineEdit(Widget);
        flowAddr4lineEdit->setObjectName(QString::fromUtf8("flowAddr4lineEdit"));

        horizontalLayout_4->addWidget(flowAddr4lineEdit);

        flowType4lineEdit = new QLineEdit(Widget);
        flowType4lineEdit->setObjectName(QString::fromUtf8("flowType4lineEdit"));

        horizontalLayout_4->addWidget(flowType4lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        flowAddr5lineEdit = new QLineEdit(Widget);
        flowAddr5lineEdit->setObjectName(QString::fromUtf8("flowAddr5lineEdit"));

        horizontalLayout_5->addWidget(flowAddr5lineEdit);

        flowType5lineEdit = new QLineEdit(Widget);
        flowType5lineEdit->setObjectName(QString::fromUtf8("flowType5lineEdit"));

        horizontalLayout_5->addWidget(flowType5lineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        flowAddr6lineEdit = new QLineEdit(Widget);
        flowAddr6lineEdit->setObjectName(QString::fromUtf8("flowAddr6lineEdit"));

        horizontalLayout_6->addWidget(flowAddr6lineEdit);

        flowType6lineEdit = new QLineEdit(Widget);
        flowType6lineEdit->setObjectName(QString::fromUtf8("flowType6lineEdit"));

        horizontalLayout_6->addWidget(flowType6lineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        flowAddr7lineEdit = new QLineEdit(Widget);
        flowAddr7lineEdit->setObjectName(QString::fromUtf8("flowAddr7lineEdit"));

        horizontalLayout_7->addWidget(flowAddr7lineEdit);

        flowType7lineEdit = new QLineEdit(Widget);
        flowType7lineEdit->setObjectName(QString::fromUtf8("flowType7lineEdit"));

        horizontalLayout_7->addWidget(flowType7lineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        flowAddr8lineEdit = new QLineEdit(Widget);
        flowAddr8lineEdit->setObjectName(QString::fromUtf8("flowAddr8lineEdit"));

        horizontalLayout_8->addWidget(flowAddr8lineEdit);

        flowType8lineEdit = new QLineEdit(Widget);
        flowType8lineEdit->setObjectName(QString::fromUtf8("flowType8lineEdit"));

        horizontalLayout_8->addWidget(flowType8lineEdit);


        verticalLayout->addLayout(horizontalLayout_8);


        verticalLayout_16->addLayout(verticalLayout);

        picturelabel = new QLabel(Widget);
        picturelabel->setObjectName(QString::fromUtf8("picturelabel"));

        verticalLayout_16->addWidget(picturelabel);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        severIPLineEdit = new QLineEdit(Widget);
        severIPLineEdit->setObjectName(QString::fromUtf8("severIPLineEdit"));

        verticalLayout_5->addWidget(severIPLineEdit);


        horizontalLayout_13->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        severComLineEdit = new QLineEdit(Widget);
        severComLineEdit->setObjectName(QString::fromUtf8("severComLineEdit"));

        verticalLayout_6->addWidget(severComLineEdit);


        horizontalLayout_13->addLayout(verticalLayout_6);

        horizontalLayout_13->setStretch(0, 2);
        horizontalLayout_13->setStretch(1, 1);

        verticalLayout_14->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_7->addWidget(label_5);

        preNumLineEdit = new QLineEdit(Widget);
        preNumLineEdit->setObjectName(QString::fromUtf8("preNumLineEdit"));

        verticalLayout_7->addWidget(preNumLineEdit);


        horizontalLayout_14->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_8->addWidget(label_6);

        flowNumLineEdit = new QLineEdit(Widget);
        flowNumLineEdit->setObjectName(QString::fromUtf8("flowNumLineEdit"));

        verticalLayout_8->addWidget(flowNumLineEdit);


        horizontalLayout_14->addLayout(verticalLayout_8);


        verticalLayout_14->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_9->addWidget(label_7);

        bloNumLineEdit = new QLineEdit(Widget);
        bloNumLineEdit->setObjectName(QString::fromUtf8("bloNumLineEdit"));

        verticalLayout_9->addWidget(bloNumLineEdit);


        horizontalLayout_15->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_10->addWidget(label_14);

        devidLineEdit = new QLineEdit(Widget);
        devidLineEdit->setObjectName(QString::fromUtf8("devidLineEdit"));
        devidLineEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout_10->addWidget(devidLineEdit);


        horizontalLayout_15->addLayout(verticalLayout_10);


        verticalLayout_14->addLayout(horizontalLayout_15);


        verticalLayout_16->addLayout(verticalLayout_14);

        verticalLayout_16->setStretch(0, 1);
        verticalLayout_16->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout_16, 0, 3, 2, 1);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout_18->addWidget(textBrowser);

        verticalLayout_18->setStretch(0, 1);

        gridLayout->addLayout(verticalLayout_18, 1, 0, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "OilDebug", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\347\273\210\347\253\257IP</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\347\273\210\347\253\257\347\253\257\345\217\243</p></body></html>", 0, QApplication::UnicodeUTF8));
        connectpushButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        funComboBox->clear();
        funComboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\347\233\270\346\234\272\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\344\273\252\350\241\250\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\345\212\237\346\224\276\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\350\201\224\347\275\221\346\265\213\350\257\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "ARM\351\207\215\345\220\257", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\345\274\200\346\210\252\346\226\255\351\230\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\345\205\263\346\210\252\346\226\255\351\230\200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Widget", "\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\216\213\345\212\233\350\241\250\345\234\260\345\235\2001</p></body></html>", 0, QApplication::UnicodeUTF8));
        preAddr1lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        preAddr2lineEdit->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        preAddr3lineEdit->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        preAddr4lineEdit->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        preAddr5lineEdit->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        preAddr6lineEdit->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        preAddr7lineEdit->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        preAddr8lineEdit->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\216\213\345\212\233\350\241\250\345\234\260\345\235\2002</p></body></html>", 0, QApplication::UnicodeUTF8));
        preAddr9lineEdit->setText(QApplication::translate("Widget", "9", 0, QApplication::UnicodeUTF8));
        preAddr10lineEdit->setText(QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8));
        preAddr11lineEdit->setText(QApplication::translate("Widget", "11", 0, QApplication::UnicodeUTF8));
        preAddr12lineEdit->setText(QApplication::translate("Widget", "12", 0, QApplication::UnicodeUTF8));
        preAddr13lineEdit->setText(QApplication::translate("Widget", "13", 0, QApplication::UnicodeUTF8));
        lpreAddr14lineEdit->setText(QApplication::translate("Widget", "14", 0, QApplication::UnicodeUTF8));
        preAddr15lineEdit->setText(QApplication::translate("Widget", "15", 0, QApplication::UnicodeUTF8));
        preAddr16lineEdit->setText(QApplication::translate("Widget", "16", 0, QApplication::UnicodeUTF8));
        readPushButton->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        modiPushButton->setText(QApplication::translate("Widget", "\344\277\256\346\224\271\345\217\202\346\225\260", 0, QApplication::UnicodeUTF8));
        confPushButton->setText(QApplication::translate("Widget", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\210\252\346\226\255\351\230\200\345\234\260\345\235\2001</p></body></html>", 0, QApplication::UnicodeUTF8));
        blocAddr1lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        blocAddr2lineEdit->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        blocAddr3lineEdit->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        blocAddr4lineEdit->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("Widget", "\346\265\201\351\207\217\350\256\241\347\261\273\345\236\213:\n"
"\n"
"\345\256\211\346\243\256:    1\n"
"\345\215\216\346\265\2671:  2\n"
"\345\215\216\346\265\2672:  3\n"
"\345\244\251\344\277\241:    4\n"
"\n"
"\350\257\267\345\260\206PC\347\232\204IPV4\345\234\260\345\235\200\350\256\276\347\275\256\346\210\220192.168.1.x(100<x<250),\345\206\215\344\275\277\347\224\250\350\257\245\350\275\257\344\273\266\350\277\233\350\241\214\350\260\203\350\257\225!", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\210\252\346\226\255\351\230\200\345\234\260\345\235\2002</p></body></html>", 0, QApplication::UnicodeUTF8));
        blocAddr5lineEdit->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        blocAddr6lineEdit->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        blocAddr7lineEdit->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        blocAddr8lineEdit->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\265\201\351\207\217\350\256\241\345\234\260\345\235\200</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\265\201\351\207\217\350\256\241\347\261\273\345\236\213</p></body></html>", 0, QApplication::UnicodeUTF8));
        flowAddr1lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowType1lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr2lineEdit->setText(QApplication::translate("Widget", "2", 0, QApplication::UnicodeUTF8));
        flowType2lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr3lineEdit->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        flowType3lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr4lineEdit->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        flowType4lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr5lineEdit->setText(QApplication::translate("Widget", "5", 0, QApplication::UnicodeUTF8));
        flowType5lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr6lineEdit->setText(QApplication::translate("Widget", "6", 0, QApplication::UnicodeUTF8));
        flowType6lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr7lineEdit->setText(QApplication::translate("Widget", "7", 0, QApplication::UnicodeUTF8));
        flowType7lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        flowAddr8lineEdit->setText(QApplication::translate("Widget", "8", 0, QApplication::UnicodeUTF8));
        flowType8lineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        picturelabel->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">Wait for picture</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250IP</p></body></html>", 0, QApplication::UnicodeUTF8));
        severIPLineEdit->setText(QApplication::translate("Widget", "219.245.77.147", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243</p></body></html>", 0, QApplication::UnicodeUTF8));
        severComLineEdit->setText(QApplication::translate("Widget", "30001", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\345\216\213\345\212\233\350\241\250\346\225\260\351\207\217</p></body></html>", 0, QApplication::UnicodeUTF8));
        preNumLineEdit->setText(QApplication::translate("Widget", "4", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\265\201\351\207\217\350\256\241\346\225\260\351\207\217</p></body></html>", 0, QApplication::UnicodeUTF8));
        flowNumLineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\346\210\252\346\226\255\351\230\200\346\225\260\351\207\217</p></body></html>", 0, QApplication::UnicodeUTF8));
        bloNumLineEdit->setText(QApplication::translate("Widget", "1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Widget", "<html><head/><body><p align=\"center\">\350\256\276\345\244\207ID</p></body></html>", 0, QApplication::UnicodeUTF8));
        devidLineEdit->setText(QApplication::translate("Widget", "0004005000", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
