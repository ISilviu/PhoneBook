#include "phonebook.h"

#include "UiPlugin.h"
#include "InMemorySQLiteStoragePlugin.h"

#include "Exceptions.h"

#include "Contact.h"


int main(int argc, char *argv[])
{
	InMemorySQLiteStoragePlugin storagePlugin;

	UiPlugin uiPlugin(argc, argv);

	storagePlugin.init();

	uiPlugin.init(std::vector<IPlugin*>{&storagePlugin});

	if(storagePlugin.run())
		return uiPlugin.run();
}
