#include "VCardForm.hpp"

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
	QObject::connect(btnCreate, SIGNAL(clicked()), this, SLOT(createVCard()));

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
	layout->addWidget(btnCreate, row++, col++);
	
	centerWidget = new QWidget(this);
	centerWidget->setLayout(layout);

	setCentralWidget(centerWidget);

	QRect fg = frameGeometry();
	fg.moveCenter(QApplication::desktop()->availableGeometry().center());
	move(fg.topLeft());
}

void VCardForm::createVCard() {
	VCardModel *m = new VCardModel();
	QString filepath = QFileDialog::getSaveFileName(0, "Save file", "", "VCard Files (*.vcf)");

	m->setFirstName(txtFirstName->text());
	m->setLastName(txtLastName->text());
	m->setEmail(txtEmail->text());
	m->setFilepath(filepath);

	if(controller.createVCard(m)) {
		QMessageBox msgBox(QMessageBox::Information, "Success", "vCard successfully created!");
		msgBox.exec();
	} else {
		QMessageBox msgBox(QMessageBox::Critical, "Error", "vCard could not be created.");
		msgBox.exec();
	}
}
