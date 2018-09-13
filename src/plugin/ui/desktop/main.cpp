#include "phonebook.h"

#include "QtUiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include <QtWidgets/QApplication>

#include "Exceptions.h"

#include <qdebug.h>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	PhoneBook phoneBookApplication;

	InMemorySQLiteStoragePlugin storagePlugin;
	phoneBookApplication.addStoragePlugin(&storagePlugin);

	QtUiPlugin uiPlugin;
	phoneBookApplication.addUiPlugin(&uiPlugin);

	try
	{
		phoneBookApplication.initiatePlugins();
		phoneBookApplication.run();
		return a.exec();
	}
	catch (CouldNotOpenDatabaseException const& e)
	{
		qDebug() << e.what();
		std::exit(EXIT_FAILURE);
	}
	catch (CouldNotCreateDatabaseTableException const& e)
	{
		qDebug() << e.what();
		std::exit(EXIT_FAILURE);

	}
}
