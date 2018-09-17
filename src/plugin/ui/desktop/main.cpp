#include "phonebook.h"

#include "UiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include <QtWidgets/QApplication>

#include "Exceptions.h"

int main(int argc, char *argv[])
{
	PhoneBook phoneBookApplication;

	InMemorySQLiteStoragePlugin storagePlugin;
	phoneBookApplication.addPlugin(&storagePlugin);	

	UiPlugin uiPlugin(argc, argv);
	phoneBookApplication.addPlugin(&uiPlugin);

	storagePlugin.init();
	try
	{
		uiPlugin.init(std::vector<IPlugin*>{&storagePlugin});

		storagePlugin.run();
		return uiPlugin.run();
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
