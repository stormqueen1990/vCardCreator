#include "VCardModel.hpp"

void VCardModel::setFirstName(QString firstName) {
	this->firstName = firstName;
}

QString VCardModel::getFirstName() {
	return firstName;
}

void VCardModel::setLastName(QString lastName) {
	this->lastName = lastName;
}

QString VCardModel::getLastName() {
	return lastName;
}

void VCardModel::setEmail(QString email) {
	this->email = email;
}

QString VCardModel::getEmail() {
	return email;
}

void VCardModel::setFilepath(QString filepath) {
	this->filepath = filepath;
}

QString VCardModel::getFilepath() {
	return filepath;
}

