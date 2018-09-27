#include "StoragePlugin.h"

IRepository<Contact, PhoneBook>* StoragePlugin::getReadModel() noexcept
{
	return dynamic_cast<IRepository<Contact, PhoneBook>*>(&_repository);
}
