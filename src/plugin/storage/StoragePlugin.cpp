#include "StoragePlugin.h"

IRepository<Contact, PhoneBook>* StoragePlugin::getReadModel() noexcept
{
	return dynamic_cast<IRepository<Contact, PhoneBook>*>(&_repository);
}

std::vector<std::string> StoragePlugin::getDependencies() const
{
	return std::vector<std::string>();
}
