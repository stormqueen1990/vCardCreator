#include "VCardController.hpp"

/**
 * Creates the vCard file, using the data from the
 * received model.
 */
bool VCardController::createVCard(VCardModel *m) {
	// Creates the file
	QFile f(m->getFilepath());
	// Creates the text stream
	QTextStream qtstr(&f);
	// Obtains current time and date
	QDateTime currDateTime = QDateTime::currentDateTime();

	// Opens the file for writing
	f.open(QIODevice::WriteOnly);

	// Ensures the file can be written to
	if(f.isOpen()) {
		std::cout << "creating vcard file...";

		// Creates the vCard file structure
		qtstr << "BEGIN:VCARD\n";
		qtstr << "VERSION:3.0\n";
		qtstr << "N:" << m->getLastName();
		qtstr << ";" << m->getFirstName();
		qtstr << "\n";
		qtstr << "FN:" << m->getFirstName();
		qtstr << " " << m->getLastName();
		qtstr << "\n";
		qtstr << "EMAIL;TYPE=PREF,INTERNET:";
		qtstr << m->getEmail() << "\n";
		qtstr << "REV:" << currDateTime.toString("yyyy-MM-dd");
		qtstr << "T" << currDateTime.toString("hh:mm:ss") << "Z\n";
		qtstr << "END:VCARD\n";
		qtstr.flush();

		// Closes the current file
		f.close();

		std::cout << "done!" << std::endl;

		return true;
	}
	
	std::cout << "error: could not write to file: " << m->getFilepath().toStdString() << std::endl;
	return false;
}
