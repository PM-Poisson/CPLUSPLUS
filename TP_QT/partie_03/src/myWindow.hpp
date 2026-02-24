#pragma once

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include <QWidget>

//Forward declaration of Qt Button
// (alternative to #include when only pointers are used in the header file)
class QPushButton;
class QCheckBox;
class QGridLayout;


//Declaration of myWindow
class myWindow: public QWidget
{
    Q_OBJECT

public:

    myWindow(QWidget *parent=nullptr);
    ~myWindow();

private slots:

	/** Close the window */
    void quitWindow();
    /** Print info about the buttons */
    void clickButton();
    /** Click on both buttons */
    void clickBothButtons();

private:

    QPushButton *quitButton;
    QPushButton *bothButtons;
    QCheckBox   *checkBox1;
    QCheckBox   *checkBox2;
    QGridLayout *mainLayout;
};

#endif