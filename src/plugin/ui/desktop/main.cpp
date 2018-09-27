#include "phonebook.h"

#include "UiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include "Contact.h"

#include "PhoneBook.h"

#include "StoragePlugin.h"

#include "Application.h"

#include "InMemorySQLiteStoragePluginSpecification.h"
#include "UiPluginSpecification.h"

#include "Graph.h"

int main(int argc, char *argv[])
{
	Application application;

	UiPluginSpecification ui;
	application.addPluginSpecification(&ui);

	InMemorySQLiteStoragePluginSpecification storage;
	application.addPluginSpecification(&storage);

	return application.run();
}
