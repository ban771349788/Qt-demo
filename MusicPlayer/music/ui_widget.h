/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidget_3;
    QWidget *page_3;
    QListWidget *listWidget_2;
    QWidget *page_2;
    QListWidget *listWidget;
    QWidget *page_4;
    QListWidget *listWidget_4;
    QWidget *page_5;
    QListWidget *listWidget_5;
    QFrame *frame;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QPushButton *pushButton_8;
    QSlider *verticalSlider;
    QPushButton *pushButton_19;
    QSlider *horizontalSlider;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_13;
    QPushButton *pushButton_18;
    QLineEdit *lineEdit;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_14;
    QPushButton *pushButton_20;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_15;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::NonModal);
        Widget->setEnabled(true);
        Widget->resize(1200, 700);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(1200, 700));
        Widget->setMaximumSize(QSize(1200, 700));
        Widget->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/ios8_Music_32px_1173465_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QLatin1String("QWidget{\n"
"\n"
"background-repeat:no-repeat;\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 640, 48, 48));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/pre.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/pre-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/pre.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 110, 350, 510));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget_3 = new QListWidget(page);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(0, 0, 350, 510));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        listWidget_3->setFont(font);
        listWidget_3->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_3->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_3->setStyleSheet(QLatin1String("QListWidget{\n"
"font: 75 12pt \"Comic Sans MS\";\n"
"background-color:transparent;\n"
"\n"
"}\n"
"QListWidget::item{\n"
"color:rgb(120,120,120);\n"
"border:none;\n"
"margin-top:3px;\n"
"\n"
"}\n"
"QListWidget::item:hover{\n"
"padding-left:4px;\n"
"margin-top:3px;\n"
"color:rgb(100,100,100);\n"
"background-color:rgba(255,255,255,0.2);\n"
"\n"
"\n"
"\n"
"}\n"
"QListWidget::item:selected{\n"
"outline:none;\n"
"margin-top:3px;\n"
"padding-left:4px;\n"
"background-color:rgba(255,255,255,0.5);\n"
"color:rgb(0,0,0);\n"
"}\n"
"QListWidget::item:!active{\n"
"margin-top:3px;\n"
"border:none;\n"
"background-color:rgba(255,255,255,0);\n"
"color:rgb(120,120,120);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        listWidget_3->setFrameShape(QFrame::NoFrame);
        listWidget_3->setFrameShadow(QFrame::Sunken);
        listWidget_3->setLineWidth(0);
        listWidget_3->setMidLineWidth(0);
        listWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_3->setDefaultDropAction(Qt::CopyAction);
        listWidget_3->setAlternatingRowColors(false);
        listWidget_3->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget_3->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget_3->setLayoutMode(QListView::SinglePass);
        listWidget_3->setSelectionRectVisible(false);
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        listWidget_2 = new QListWidget(page_3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(0, 0, 350, 510));
        listWidget_2->setFont(font);
        listWidget_2->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_2->setStyleSheet(QLatin1String("QListWidget{\n"
"font: 75 12pt \"Comic Sans MS\";\n"
"background-color:transparent;\n"
"\n"
"}\n"
"QListWidget::item{\n"
"color:rgb(120,120,120);\n"
"border:none;\n"
"margin-top:3px;\n"
"\n"
"}\n"
"QListWidget::item:hover{\n"
"padding-left:4px;\n"
"margin-top:3px;\n"
"color:rgb(100,100,100);\n"
"background-color:rgba(255,255,255,0.2);\n"
"\n"
"\n"
"\n"
"}\n"
"QListWidget::item:selected{\n"
"outline:none;\n"
"margin-top:3px;\n"
"padding-left:4px;\n"
"background-color:rgba(255,255,255,0.5);\n"
"color:rgb(0,0,0);\n"
"}\n"
"QListWidget::item:!active{\n"
"margin-top:3px;\n"
"border:none;\n"
"background-color:rgba(255,255,255,0);\n"
"color:rgb(120,120,120);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        listWidget_2->setFrameShape(QFrame::NoFrame);
        listWidget_2->setFrameShadow(QFrame::Plain);
        listWidget_2->setLineWidth(0);
        listWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget_2->setBatchSize(100);
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        listWidget = new QListWidget(page_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 350, 510));
        listWidget->setFont(font);
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setStyleSheet(QLatin1String("QListWidget{\n"
"font: 75 12pt \"Comic Sans MS\";\n"
"background-color:transparent;\n"
"\n"
"}\n"
"QListWidget::item{\n"
"color:rgb(120,120,120);\n"
"border:none;\n"
"margin-top:3px;\n"
"\n"
"}\n"
"QListWidget::item:hover{\n"
"padding-left:4px;\n"
"margin-top:3px;\n"
"color:rgb(100,100,100);\n"
"background-color:rgba(255,255,255,0.2);\n"
"\n"
"\n"
"\n"
"}\n"
"QListWidget::item:selected{\n"
"outline:none;\n"
"margin-top:3px;\n"
"padding-left:4px;\n"
"background-color:rgba(255,255,255,0.5);\n"
"color:rgb(0,0,0);\n"
"}\n"
"QListWidget::item:!active{\n"
"margin-top:3px;\n"
"border:none;\n"
"background-color:rgba(255,255,255,0);\n"
"color:rgb(120,120,120);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setFrameShadow(QFrame::Plain);
        listWidget->setLineWidth(0);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSortingEnabled(false);
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        listWidget_4 = new QListWidget(page_4);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));
        listWidget_4->setGeometry(QRect(0, 0, 350, 510));
        listWidget_4->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_4->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_4->setStyleSheet(QLatin1String("QListWidget{\n"
"font: 75 12pt \"Comic Sans MS\";\n"
"background-color:transparent;\n"
"\n"
"}\n"
"QListWidget::item{\n"
"color:rgb(120,120,120);\n"
"border:none;\n"
"margin-top:3px;\n"
"\n"
"}\n"
"QListWidget::item:hover{\n"
"padding-left:4px;\n"
"margin-top:3px;\n"
"color:rgb(100,100,100);\n"
"background-color:rgba(255,255,255,0.2);\n"
"\n"
"\n"
"\n"
"}\n"
"QListWidget::item:selected{\n"
"outline:none;\n"
"margin-top:3px;\n"
"padding-left:4px;\n"
"background-color:rgba(255,255,255,0.5);\n"
"color:rgb(0,0,0);\n"
"}\n"
"QListWidget::item:!active{\n"
"margin-top:3px;\n"
"border:none;\n"
"background-color:rgba(255,255,255,0);\n"
"color:rgb(120,120,120);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        listWidget_4->setFrameShape(QFrame::NoFrame);
        listWidget_4->setFrameShadow(QFrame::Raised);
        listWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        listWidget_5 = new QListWidget(page_5);
        listWidget_5->setObjectName(QStringLiteral("listWidget_5"));
        listWidget_5->setGeometry(QRect(0, 0, 350, 510));
        listWidget_5->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        listWidget_5->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget_5->setStyleSheet(QLatin1String("QListWidget{\n"
"font: 75 12pt \"Comic Sans MS\";\n"
"background-color:transparent;\n"
"\n"
"}\n"
"QListWidget::item{\n"
"color:rgb(120,120,120);\n"
"border:none;\n"
"margin-top:3px;\n"
"\n"
"}\n"
"QListWidget::item:hover{\n"
"padding-left:4px;\n"
"margin-top:3px;\n"
"color:rgb(100,100,100);\n"
"background-color:rgba(255,255,255,0.2);\n"
"\n"
"\n"
"\n"
"}\n"
"QListWidget::item:selected{\n"
"outline:none;\n"
"margin-top:3px;\n"
"padding-left:4px;\n"
"background-color:rgba(255,255,255,0.5);\n"
"color:rgb(0,0,0);\n"
"}\n"
"QListWidget::item:!active{\n"
"margin-top:3px;\n"
"border:none;\n"
"background-color:rgba(255,255,255,0);\n"
"color:rgb(120,120,120);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        listWidget_5->setFrameShape(QFrame::NoFrame);
        listWidget_5->setLineWidth(0);
        listWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget_5->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget_5->setSelectionBehavior(QAbstractItemView::SelectItems);
        stackedWidget->addWidget(page_5);
        frame = new QFrame(Widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setEnabled(true);
        frame->setGeometry(QRect(0, 0, 1200, 700));
        frame->setMinimumSize(QSize(1200, 700));
        frame->setMaximumSize(QSize(1200, 700));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        pushButton_17 = new QPushButton(frame);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(1165, 0, 32, 32));
        pushButton_17->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_17->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/quit.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"\n"
"background-color: rgba(230,0,0,0.5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_16 = new QPushButton(frame);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(1100, 0, 32, 32));
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/min.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1150, 650, 32, 32));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        verticalSlider = new QSlider(frame);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(1150, 460, 35, 181));
        verticalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        verticalSlider->setStyleSheet(QString::fromUtf8(" QSlider \n"
"    {  \n"
"        background-color: rgba(255,255,255,0.2);\n"
"        min-width:5px; \n"
"        max-width:5px;\n"
"        border:15px solid rgba(255,255,255,0.2); \n"
"    }\n"
"     QSlider::add-page:vertical\n"
"     {      \n"
"       \n"
"	    background-color: rgb(250, 250, 0);\n"
"        width:4px;\n"
"     }\n"
"     QSlider::sub-page:vertical  \n"
"    {\n"
"        background-color: rgba(255,255,255,0.5); \n"
"        width:4px;\n"
"     }\n"
"    QSlider::groove:vertical \n"
"    {\n"
"        background:transparent;\n"
"        width:6px;\n"
"    }\n"
"    QSlider::handle:vertical \n"
"    {\n"
"         height: 13px;\n"
"        width:13px;\n"
" \n"
" margin: -0 -4px; \n"
"	border-image: url(:/image/image/\345\234\206\345\275\242 (10).png);\n"
"     }"));
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::NoTicks);
        pushButton_19 = new QPushButton(frame);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(1132, 0, 32, 32));
        pushButton_19->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/max.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(300, 650, 661, 31));
        horizontalSlider->setCursor(QCursor(Qt::PointingHandCursor));
        horizontalSlider->setStyleSheet(QString::fromUtf8("\n"
"    QSlider::add-page:Horizontal\n"
"     {     \n"
"background-color: rgba(255, 255, 255,100);\n"
"        height:4px;  \n"
"     } \n"
"     QSlider::sub-page:Horizontal   \n"
"    {  \n"
"background-color: rgb(255, 255, 255);\n"
"        height:4px;\n"
"     }\n"
"    QSlider::groove:Horizontal   \n"
"    { \n"
"        background:transparent; \n"
"        height:4px;\n"
"    }  \n"
"    QSlider::handle:Horizontal  \n"
"    { \n"
"        height:16px; \n"
"        width:16px; \n"
"	\n"
"	border-image: url(:/image/image/\345\234\206\345\275\242 (9).png);\n"
"  margin: -6 0px; \n"
"    }\n"
"      \n"
""));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1066, 650, 32, 32));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/position.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-image: url(:/image/image/image-hover/position-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/position.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(916, -32, 32, 32));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("\n"
"QPushButton\n"
"{\n"
"color:transparent;\n"
"background-image: url(:/image/image/image/add.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-image: url(:/image/image/image-hover/add-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/add.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
""));
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1020, -32, 32, 32));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color: rgba(255, 255, 255,0);\n"
"background-image: url(:/image/image/image/setting.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"background-image: url(:/image/image/image-hover/setting.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/setting.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
""));
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(968, -32, 32, 32));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/face.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"color:transparent;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"background-image: url(:/image/image/face-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
" background-image: url(:/image/image/face.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_13 = new QPushButton(frame);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(864, -32, 32, 32));
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:transparent;\n"
"background-image: url(:/image/image/image/left-arrow.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-image: url(:/image/image/image-hover/left-arrow-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/left-arrow.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_18 = new QPushButton(frame);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(750, 20, 32, 32));
        pushButton_18->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_18->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/sereach.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"background-image: url(:/image/image/image-hover/sereach-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/sereach.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(400, 20, 341, 32));
        lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color: rgba(255, 255, 255,150);\n"
"border-style:outset;\n"
"\n"
"border-width:0px;\n"
"\n"
"border-radius:10px;\n"
"border-color: rgba(0,0,0,100);\n"
"font:bold 14px;\n"
"color:rgb(180,180,180);\n"
"padding:6px;\n"
"}"));
        lineEdit->setInputMethodHints(Qt::ImhNone);
        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(80, 60, 32, 32));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/like.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/like-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/like.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 60, 32, 32));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/music.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/music-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/music.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_12 = new QPushButton(frame);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(160, 60, 31, 31));
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/list.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/list-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/list.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(1024, 650, 32, 32));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_14 = new QPushButton(frame);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(982, 650, 32, 32));
        pushButton_14->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_20 = new QPushButton(frame);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(1068, 0, 32, 32));
        pushButton_20->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_20->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/tr.png);\n"
"background-color: rgba(255, 255, 255,0);\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"\n"
"\n"
"	background-color: rgb(255, 255, 255,100);\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgba(95, 95, 95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:inset;\n"
"color:rgba(0,0,0,100);\n"
"\n"
"}\n"
""));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 640, 48, 48));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/next.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-image: url(:/image/image/image-hover/next-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/next.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 640, 48, 48));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_21 = new QPushButton(frame);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(1108, 650, 32, 32));
        pushButton_21->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_21->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/playlist.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/playlist-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/playlist.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_22 = new QPushButton(frame);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(240, 60, 32, 32));
        pushButton_22->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_22->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-image: url(:/image/image/image/play-resently.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
"	background-image: url(:/image/image/image-hover/play-resently-hover.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-image: url(:/image/image/image/play-resently.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        pushButton_15 = new QPushButton(frame);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(320, 60, 32, 32));
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_15->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"border:none;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"background-repeat:no-repeat;\n"
"background-position:center center;\n"
"\n"
"}\n"
""));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 291, 31));
        label_5->setStyleSheet(QLatin1String("QLabel{\n"
"\n"
"	font: 75 pt \"Comic Sans MS\";\n"
"color:rgba(255,255,255,0.5);\n"
"   \n"
" \n"
"\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(850, 630, 111, 21));
        label_2->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Comic Sans MS\";\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 600, 521, 31));
        label->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Comic Sans MS\";\n"
"color: rgb(75, 75, 75);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 390, 510, 32));
        label_3->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Comic Sans MS\";\n"
"color: rgb(75, 75, 75);"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 450, 460, 32));
        label_4->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Comic Sans MS\";\n"
"color: rgb(75, 75, 75);"));
        frame->raise();
        pushButton_4->raise();
        stackedWidget->raise();

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\210\221\347\232\204\351\237\263\344\271\220", 0));
        pushButton_4->setText(QString());
        pushButton_17->setText(QString());
        pushButton_16->setText(QString());
        pushButton_8->setText(QString());
        pushButton_19->setText(QString());
        pushButton_7->setText(QString());
        pushButton->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_13->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QApplication::translate("Widget", "\346\220\234\347\264\242", 0));
#endif // QT_NO_TOOLTIP
        pushButton_18->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Widget", "\350\276\223\345\205\245\346\255\214\346\233\262\346\210\226\346\255\214\346\211\213", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Widget", "\350\276\223\345\205\245\346\255\214\346\233\262", 0));
#endif // QT_NO_STATUSTIP
        pushButton_11->setText(QString());
        pushButton_10->setText(QString());
        pushButton_12->setText(QString());
        pushButton_9->setText(QString());
        pushButton_14->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_20->setToolTip(QApplication::translate("Widget", "\346\233\264\345\244\232", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_20->setStatusTip(QApplication::translate("Widget", "\346\233\264\345\244\232", 0));
#endif // QT_NO_STATUSTIP
        pushButton_20->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_21->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_22->setToolTip(QApplication::translate("Widget", "\346\234\200\350\277\221\346\222\255\346\224\276", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_22->setStatusTip(QApplication::translate("Widget", "\346\234\200\350\277\221\346\222\255\346\224\276", 0));
#endif // QT_NO_STATUSTIP
        pushButton_22->setText(QString());
        pushButton_15->setText(QString());
        label_5->setText(QApplication::translate("Widget", "\351\225\277\350\203\226\347\232\204\345\234\237\350\261\206", 0));
        label_2->setText(QString());
        label->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
