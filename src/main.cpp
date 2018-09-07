#include "phonebook.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PhoneBook w;
	w.show();
	return a.exec();
}
