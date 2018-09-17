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

	uiPlugin.init(std::vector<IPlugin*>{&storagePlugin});

	if(storagePlugin.run())
		return uiPlugin.run();
}
