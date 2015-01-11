#ifndef VCARDCONTROLLER_HPP
#define VCARDCONTROLLER_HPP

#include "VCardModel.hpp"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class VCardController {
public:
	bool createVCard(VCardModel *m);
};

#endif //VCARDCONTROLLER_HPP
