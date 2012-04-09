#ifndef VCARDFORM_HPP
#define VCARDFORM_HPP

#include <QtGui>
#include <iostream>
#include "VCardController.hpp"

class VCardForm : public QMainWindow {
Q_OBJECT
public:
	VCardForm();

private:
	QWidget *centerWidget;
	QLineEdit *txtFirstName;
	QLineEdit *txtLastName;
	QLineEdit *txtEmail;
	QLabel *lblFirstName;
	QLabel *lblLastName;
	QLabel *lblEmail;
	QPushButton *btnCreate;

	VCardController controller;
public slots:
	void createVCard();
};

#endif // VCARDFORM_HPP
