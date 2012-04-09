#ifndef VCARDMODEL_HPP
#define VCARDMODEL_HPP

#include <QString>

class VCardModel {
private:
	QString firstName;
	QString lastName;
	QString email;
	QString filepath;
public:
	void setFirstName(QString firstName);
	QString getFirstName();
	void setLastName(QString lastName);
	QString getLastName();
	void setEmail(QString email);
	QString getEmail();
	void setFilepath(QString filepath);
	QString getFilepath();
};

#endif //VCARDMODEL_HPP
