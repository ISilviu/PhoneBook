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

	std::vector<std::pair<int, int>> edges{ {0,1}, {2,0} };

	Graph myGraph(3, edges.begin(), edges.end());

	auto sorted = myGraph.topologicalSort();
	//Application application;


	//UiPluginSpecification ui;
	//application.addPluginSpecification(&ui);

	//InMemorySQLiteStoragePluginSpecification storage;
	//application.addPluginSpecification(&storage);


	//return application.run();
}
