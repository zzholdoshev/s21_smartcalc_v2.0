/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_right_parenthesis;
    QPushButton *pushButton_div;
    QPushButton *pushButton_9;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_0;
    QPushButton *pushButton_left_parenthesis;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_8;
    QPushButton *pushButton_mul;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(466, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setHorizontalSpacing(1);
        formLayout->setVerticalSpacing(1);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        QFont font;
        font.setPointSize(16);
        textBrowser->setFont(font);
        textBrowser->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::SpanningRole, textBrowser);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setMaxLength(255);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setPointSize(14);
        pushButton->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButton);


        verticalLayout_2->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        sizePolicy.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        pushButton_mod->setFont(font2);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_mod->setFlat(false);

        gridLayout->addWidget(pushButton_mod, 1, 3, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_6->setFlat(false);

        gridLayout->addWidget(pushButton_6, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName("pushButton_clear");
        sizePolicy.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy);
        pushButton_clear->setFont(font2);
        pushButton_clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_clear->setFlat(false);

        gridLayout->addWidget(pushButton_clear, 1, 0, 1, 1);

        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        sizePolicy.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
        pushButton_minus->setSizePolicy(sizePolicy);
        pushButton_minus->setFont(font2);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_minus->setFlat(false);

        gridLayout->addWidget(pushButton_minus, 4, 3, 1, 1);

        pushButton_right_parenthesis = new QPushButton(centralwidget);
        pushButton_right_parenthesis->setObjectName("pushButton_right_parenthesis");
        sizePolicy.setHeightForWidth(pushButton_right_parenthesis->sizePolicy().hasHeightForWidth());
        pushButton_right_parenthesis->setSizePolicy(sizePolicy);
        pushButton_right_parenthesis->setFont(font2);
        pushButton_right_parenthesis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_right_parenthesis->setFlat(false);

        gridLayout->addWidget(pushButton_right_parenthesis, 1, 2, 1, 1);

        pushButton_div = new QPushButton(centralwidget);
        pushButton_div->setObjectName("pushButton_div");
        sizePolicy.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy);
        pushButton_div->setFont(font2);
        pushButton_div->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_div->setFlat(false);

        gridLayout->addWidget(pushButton_div, 2, 3, 1, 1);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_9->setFlat(false);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_pi = new QPushButton(centralwidget);
        pushButton_pi->setObjectName("pushButton_pi");
        sizePolicy.setHeightForWidth(pushButton_pi->sizePolicy().hasHeightForWidth());
        pushButton_pi->setSizePolicy(sizePolicy);
        pushButton_pi->setFont(font1);
        pushButton_pi->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #808080;\n"
"border: 1px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_pi->setFlat(false);

        gridLayout->addWidget(pushButton_pi, 5, 2, 1, 1);

        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName("pushButton_pow");
        sizePolicy.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy);
        pushButton_pow->setFont(font2);
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_pow->setFlat(false);

        gridLayout->addWidget(pushButton_pow, 2, 4, 1, 1);

        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_1->setFlat(false);

        gridLayout->addWidget(pushButton_1, 4, 2, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_3->setFlat(false);

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_5->setFlat(false);

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        sizePolicy.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy);
        pushButton_equal->setFont(font1);
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color : white;\n"
"background-color : #B03608\n"
"}"));
        pushButton_equal->setFlat(false);

        gridLayout->addWidget(pushButton_equal, 3, 4, 3, 1);

        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy1);
        pushButton_dot->setFont(font1);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #808080;\n"
"border: 1px;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_dot->setFlat(false);

        gridLayout->addWidget(pushButton_dot, 5, 1, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 3, 2, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(0, 0));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_7->setFlat(false);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        sizePolicy1.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy1);
        pushButton_0->setFont(font2);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_0->setFlat(false);

        gridLayout->addWidget(pushButton_0, 5, 0, 1, 1);

        pushButton_left_parenthesis = new QPushButton(centralwidget);
        pushButton_left_parenthesis->setObjectName("pushButton_left_parenthesis");
        sizePolicy.setHeightForWidth(pushButton_left_parenthesis->sizePolicy().hasHeightForWidth());
        pushButton_left_parenthesis->setSizePolicy(sizePolicy);
        pushButton_left_parenthesis->setFont(font2);
        pushButton_left_parenthesis->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_left_parenthesis->setFlat(false);

        gridLayout->addWidget(pushButton_left_parenthesis, 1, 1, 1, 1);

        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        sizePolicy.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy);
        pushButton_sqrt->setFont(font2);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_sqrt->setFlat(false);

        gridLayout->addWidget(pushButton_sqrt, 1, 4, 1, 1);

        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        sizePolicy1.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy1);
        pushButton_plus->setFont(font2);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_plus->setFlat(false);

        gridLayout->addWidget(pushButton_plus, 5, 3, 1, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font2);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color: #808080;\n"
"border: 1px;\n"
"font: bold;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_8->setFlat(false);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_mul = new QPushButton(centralwidget);
        pushButton_mul->setObjectName("pushButton_mul");
        sizePolicy.setHeightForWidth(pushButton_mul->sizePolicy().hasHeightForWidth());
        pushButton_mul->setSizePolicy(sizePolicy);
        pushButton_mul->setFont(font2);
        pushButton_mul->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: white; \n"
"background-color : #A9A9A9;\n"
"border: 1px;\n"
"font : bold\n"
"}\n"
"QPushButton:pressed {\n"
"background-color : green;\n"
"}\n"
"\n"
""));
        pushButton_mul->setFlat(false);

        gridLayout->addWidget(pushButton_mul, 3, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "s21_smartcalc", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:16pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>digits[0-9]</p><p>functions (si = SIN, c = COS , etc)</p><p> x = [n] for setting x variable</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "\342\200\223", nullptr));
        pushButton_right_parenthesis->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "\320\237", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_left_parenthesis->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_mul->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
