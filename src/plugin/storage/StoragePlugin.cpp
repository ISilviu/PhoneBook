#include "StoragePlugin.h"


void StoragePlugin::init()
{

}

int StoragePlugin::run()
{
	return 0;
}

void StoragePlugin::shutDown()
{
}

IRepository<Contact>* StoragePlugin::getReadModel() noexcept
{
	return dynamic_cast<IRepository<Contact>*>(&_repository);
}
