/********************************************************************************
** Form generated from reading UI file 'graph_window.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_WINDOW_H
#define UI_GRAPH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graph_window
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;
    QFormLayout *formLayout_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QDialog *graph_window)
    {
        if (graph_window->objectName().isEmpty())
            graph_window->setObjectName("graph_window");
        graph_window->resize(557, 433);
        verticalLayout = new QVBoxLayout(graph_window);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QCustomPlot(graph_window);
        widget->setObjectName("widget");

        verticalLayout->addWidget(widget);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        lineEdit_5 = new QLineEdit(graph_window);
        lineEdit_5->setObjectName("lineEdit_5");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit_5);

        pushButton = new QPushButton(graph_window);
        pushButton->setObjectName("pushButton");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, pushButton);


        verticalLayout->addLayout(formLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lineEdit_2 = new QLineEdit(graph_window);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 2, 3, 1, 1);

        lineEdit_3 = new QLineEdit(graph_window);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout->addWidget(lineEdit_3, 4, 1, 1, 1);

        lineEdit_4 = new QLineEdit(graph_window);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout->addWidget(lineEdit_4, 4, 3, 1, 1);

        lineEdit = new QLineEdit(graph_window);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        label = new QLabel(graph_window);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(graph_window);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 2, 1, 1);

        label_4 = new QLabel(graph_window);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 2, 1, 1);

        label_3 = new QLabel(graph_window);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);

        retranslateUi(graph_window);

        QMetaObject::connectSlotsByName(graph_window);
    } // setupUi

    void retranslateUi(QDialog *graph_window)
    {
        graph_window->setWindowTitle(QCoreApplication::translate("graph_window", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("graph_window", "Plot", nullptr));
        label->setText(QCoreApplication::translate("graph_window", "X_MIN", nullptr));
        label_2->setText(QCoreApplication::translate("graph_window", "X_MAX", nullptr));
        label_4->setText(QCoreApplication::translate("graph_window", "Y_MAX", nullptr));
        label_3->setText(QCoreApplication::translate("graph_window", "Y_MIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_window: public Ui_graph_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_WINDOW_H
