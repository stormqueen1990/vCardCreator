#include "VCardForm.hpp"
#include <QApplication>

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	VCardForm vCardForm;
	vCardForm.show();
	return app.exec();
}
