#ifndef VCARDFORM_HPP
#define VCARDFORM_HPP

#include <iostream>

#include <QMainWindow>

#include "VCardController.hpp"

QT_BEGIN_NAMESPACE
class QLabel;
class QWidget;
class QLineEdit;
class QPushButton;
class QVBoxLayout;
class QGridLayout;
class QHBoxLayout;
QT_END_NAMESPACE

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
	QVBoxLayout *windowLayout;
	QGridLayout *fieldGridLayout;
	QHBoxLayout *buttonBarLayout;

	VCardController controller;

	void cleanScreenFields();
public slots:
	void createVCard();
	void quit();
};

#endif // VCARDFORM_HPP
