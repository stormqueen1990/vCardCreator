#include "VCardForm.hpp"

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>

/*
 * Constructs the interface.
 */
VCardForm::VCardForm() {
	// VBox fieldGridLayout to contain all fieldGridLayouts
	windowLayout = new QVBoxLayout();
	windowLayout->setSpacing(5);

	// HBox fieldGridLayout to contain the buttons
	buttonBarLayout = new QHBoxLayout();

	// First name field
	txtFirstName = new QLineEdit();
	// First name label
	lblFirstName = new QLabel("First name:");
	// Last name field
	txtLastName = new QLineEdit();
	// Last name label
	lblLastName = new QLabel("Last name:");
	// Email field
	txtEmail = new QLineEdit();
	// Email label
	lblEmail = new QLabel("Email:");

	// Create button
	btnCreate = new QPushButton("&Create");
	// Connects to the slot
	QObject::connect(btnCreate, SIGNAL(clicked()), this, SLOT(createVCard()));

	// Quit button
	btnQuit = new QPushButton("&Quit");
	// Connects to the slot
	QObject::connect(btnQuit, SIGNAL(clicked()), this, SLOT(quit()));

	// Creates the button bar
	buttonBarLayout->addWidget(btnCreate);
	buttonBarLayout->addWidget(btnQuit);

	// Creates the fieldGridLayout
	fieldGridLayout = new QGridLayout(); 
	int col = 1;
	int row = 1;
	// creates the first row
	fieldGridLayout->addWidget(lblFirstName, row, col++);
	fieldGridLayout->addWidget(txtFirstName, row++, col++);

	col = 1;
	// second row
	fieldGridLayout->addWidget(lblLastName, row, col++);
	fieldGridLayout->addWidget(txtLastName, row++, col++);

	col = 1;
	// third row
	fieldGridLayout->addWidget(lblEmail, row, col++);
	fieldGridLayout->addWidget(txtEmail, row++, col++);

	// Adds the field grid and button bar to a VBoxLayout
	windowLayout->addLayout(fieldGridLayout);
	windowLayout->addLayout(buttonBarLayout);
	
	// creates a new widget to be the central one in this window
	centerWidget = new QWidget(this);
	// sets the constructed fieldGridLayout
	centerWidget->setLayout(windowLayout);

	// sets the central widget
	setCentralWidget(centerWidget);

	// centralizes the window
	QRect fg = frameGeometry();
	fg.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(fg.center());
}

/*
 * Destroys the dinamically-allocated objects.
 */
VCardForm::~VCardForm() {
	delete txtFirstName;
	delete txtLastName;
	delete txtEmail;
	delete lblFirstName;
	delete lblLastName;
	delete lblEmail;
	delete btnCreate;
	delete btnQuit;
	delete centerWidget;
}

/*
 * Cleans the screen fields for a new input.
 */
void VCardForm::cleanScreenFields() {
	txtFirstName->setText(NULL);
	txtLastName->setText(NULL);
	txtEmail->setText(NULL);
	txtFirstName->setFocus();
}

/*
 * Creates the model and calls the controller to build a
 * vCard using the model data.
 */
void VCardForm::createVCard() {
	VCardModel m;
	// Opens the file selection window
	QString filepath = QFileDialog::getSaveFileName(0, "Save file", "", "VCard Files (*.vcf)");

	// Creates the model
	m.setFirstName(txtFirstName->text());
	m.setLastName(txtLastName->text());
	m.setEmail(txtEmail->text());
	m.setFilepath(filepath);

	// Calls the controller for building the vCard file
	if(controller.createVCard(&m)) {
		// If succeeds, shows a success message
		QMessageBox msgBox(QMessageBox::Information, "Success", "vCard successfully created!");
		msgBox.exec();
		cleanScreenFields();
	} else {
		// If not, shows an error message
		QMessageBox msgBox(QMessageBox::Critical, "Error", "vCard could not be created.");
		msgBox.exec();
	}
}

/*
 * Quits the program.
 */
void VCardForm::quit() {
	QApplication::exit(0);
}
