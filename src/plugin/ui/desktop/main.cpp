#include "phonebook.h"

#include "QtUiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include <QtWidgets/QApplication>

#include "Exceptions.h"

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	PhoneBook phoneBookApplication;

	InMemorySQLiteStoragePlugin storagePlugin;
	phoneBookApplication.addPlugin(&storagePlugin);	

	QtUiPlugin uiPlugin;
	phoneBookApplication.addPlugin(&uiPlugin);

	storagePlugin.init();
	try
	{
		uiPlugin.init(std::vector<IPlugin*>{&storagePlugin});

		storagePlugin.run();
		uiPlugin.run();
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
	catch (NonMatchingDependencyTypeException const& e)
	{
		std::exit(EXIT_FAILURE);
	}
}
