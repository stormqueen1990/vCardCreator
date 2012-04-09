#ifndef VCARDFORM_HPP
#define VCARDFORM_HPP

#include <QtGui>
#include <QApplication>
#include <iostream>
#include "VCardController.hpp"

class VCardForm : public QMainWindow {
Q_OBJECT
public:
	VCardForm();
	~VCardForm();

private:
	QWidget *centerWidget;
	QLineEdit *txtFirstName;
	QLineEdit *txtLastName;
	QLineEdit *txtEmail;
	QLabel *lblFirstName;
	QLabel *lblLastName;
	QLabel *lblEmail;
	QPushButton *btnCreate;
	QPushButton *btnQuit;

	VCardController controller;
public slots:
	void createVCard();
	void quit();
};

#endif // VCARDFORM_HPP
