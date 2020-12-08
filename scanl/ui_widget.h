/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue Dec 8 15:58:32 2020
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
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <qprogressindicator.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QProgressIndicator *scan;
    QPushButton *btn_start;
    QPushButton *btn_stop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(551, 461);
        scan = new QProgressIndicator(Widget);
        scan->setObjectName(QString::fromUtf8("scan"));
        scan->setGeometry(QRect(200, 180, 101, 51));
        btn_start = new QPushButton(Widget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(410, 190, 75, 23));
        btn_stop = new QPushButton(Widget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(410, 230, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        btn_start->setText(QApplication::translate("Widget", "start", 0, QApplication::UnicodeUTF8));
        btn_stop->setText(QApplication::translate("Widget", "stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
