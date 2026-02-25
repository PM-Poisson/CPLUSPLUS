/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *quit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_scene;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_damping;
    QLabel *label_coeff;
    QSlider *bounce_coeff_slider;
    QSlider *damping_slider;
    QLabel *bounces_number;
    QLabel *label_bounces;
    QPushButton *draw;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(806, 499);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        quit = new QPushButton(centralwidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(690, 410, 92, 27));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 751, 301));
        layout_scene = new QVBoxLayout(verticalLayoutWidget);
        layout_scene->setObjectName(QString::fromUtf8("layout_scene"));
        layout_scene->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 330, 551, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_damping = new QLabel(gridLayoutWidget);
        label_damping->setObjectName(QString::fromUtf8("label_damping"));

        gridLayout->addWidget(label_damping, 1, 0, 1, 1);

        label_coeff = new QLabel(gridLayoutWidget);
        label_coeff->setObjectName(QString::fromUtf8("label_coeff"));

        gridLayout->addWidget(label_coeff, 3, 0, 1, 1);

        bounce_coeff_slider = new QSlider(gridLayoutWidget);
        bounce_coeff_slider->setObjectName(QString::fromUtf8("bounce_coeff_slider"));
        bounce_coeff_slider->setValue(99);
        bounce_coeff_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(bounce_coeff_slider, 3, 1, 1, 1);

        damping_slider = new QSlider(gridLayoutWidget);
        damping_slider->setObjectName(QString::fromUtf8("damping_slider"));
        damping_slider->setValue(20);
        damping_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(damping_slider, 1, 1, 1, 1);

        bounces_number = new QLabel(gridLayoutWidget);
        bounces_number->setObjectName(QString::fromUtf8("bounces_number"));

        gridLayout->addWidget(bounces_number, 1, 3, 1, 1);

        label_bounces = new QLabel(gridLayoutWidget);
        label_bounces->setObjectName(QString::fromUtf8("label_bounces"));

        gridLayout->addWidget(label_bounces, 1, 2, 1, 1);

        draw = new QPushButton(gridLayoutWidget);
        draw->setObjectName(QString::fromUtf8("draw"));

        gridLayout->addWidget(draw, 3, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        quit->raise();
        verticalLayoutWidget->raise();
        gridLayoutWidget->raise();
        draw->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 806, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_damping->setText(QCoreApplication::translate("MainWindow", "damping : 0.04", nullptr));
        label_coeff->setText(QCoreApplication::translate("MainWindow", "bounce coeff : 1.00", nullptr));
        bounces_number->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_bounces->setText(QCoreApplication::translate("MainWindow", "bounces on wall :", nullptr));
        draw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
