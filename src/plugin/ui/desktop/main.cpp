#include "Application.h"

#include "InMemorySQLiteStoragePluginSpecification.h"
#include "UiPluginSpecification.h"

int main(int argc, char *argv[])
{
	Application application;

	UiPluginSpecification ui;
	application.addPluginSpecification(&ui);

	InMemorySQLiteStoragePluginSpecification storage;
	application.addPluginSpecification(&storage);

	return application.run();
}
