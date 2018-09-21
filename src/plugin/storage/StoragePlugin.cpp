#include "StoragePlugin.h"

IRepository<Contact>* StoragePlugin::getReadModel() noexcept
{
	return dynamic_cast<IRepository<Contact>*>(&_repository);
}
