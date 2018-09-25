#include "phonebook.h"

#include "UiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include "Contact.h"

#include "PhoneBook.h"

#include "StoragePlugin.h"

#include "Application.h"

int main(int argc, char *argv[])
{
	Application application;

	InMemorySQLiteStoragePlugin storagePlugin;
	application.addPlugin(&storagePlugin);

	UiPlugin uiPlugin(argc, argv);
	application.addPlugin(&uiPlugin);
	
	return application.run();
}
