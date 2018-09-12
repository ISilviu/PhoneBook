#include "phonebook.h"
#include <QtWidgets/QApplication>

#include "Exceptions.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PhoneBook w;
	try
	{
		w.prepareDatabaseForUsage();
		w.show();
		return a.exec();
	}
	catch (CouldNotOpenDatabaseException const& e)
	{
		std::exit(EXIT_FAILURE);
	}
	catch (CouldNotCreateDatabaseTableException const& e)
	{
		std::exit(EXIT_FAILURE);
	}
}
