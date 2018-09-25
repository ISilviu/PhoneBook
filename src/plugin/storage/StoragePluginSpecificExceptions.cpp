#include "StoragePluginSpecificExceptions.h"

CouldNotOpenDatabaseException::CouldNotOpenDatabaseException(std::string_view errorMessage)
	:std::runtime_error(errorMessage.data())
{}

CouldNotCreateDatabaseException::CouldNotCreateDatabaseException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}


CouldNotCreateDatabaseInMemoryException::CouldNotCreateDatabaseInMemoryException(std::string_view errorMessage)
	: CouldNotCreateDatabaseException(errorMessage.data())
{}


CouldNotCreateDatabaseTableException::CouldNotCreateDatabaseTableException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}


CouldNotAddContactException::CouldNotAddContactException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}

CouldNotSearchForTheContactException::CouldNotSearchForTheContactException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}


CouldNotUpdateContactException::CouldNotUpdateContactException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}

CouldNotDeleteContactException::CouldNotDeleteContactException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}
