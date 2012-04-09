#include "VCardForm.hpp"

/*
 * Constructs the interface.
 */
VCardForm::VCardForm() {
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

	// Creates the layout
	QGridLayout *layout = new QGridLayout(this);
	int col = 1;
	int row = 1;
	// creates the first row
	layout->addWidget(lblFirstName, row, col++);
	layout->addWidget(txtFirstName, row++, col++);

	col = 1;
	// second row
	layout->addWidget(lblLastName, row, col++);
	layout->addWidget(txtLastName, row++, col++);

	col = 1;
	// third row
	layout->addWidget(lblEmail, row, col++);
	layout->addWidget(txtEmail, row++, col++);

	col = 1;
	// fourth row
	layout->addWidget(btnCreate, row, col++);
	layout->addWidget(btnQuit, row++, col++);
	
	// creates a new widget to be the central one in this window
	centerWidget = new QWidget(this);
	// sets the constructed layout
	centerWidget->setLayout(layout);

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
