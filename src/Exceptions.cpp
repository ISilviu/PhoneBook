#include "Exceptions.h"

CouldNotOpenDatabaseException::CouldNotOpenDatabaseException(std::string const& errorMessage)
	:std::runtime_error(errorMessage)
{}

CouldNotCreateDatabaseException::CouldNotCreateDatabaseException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}



CouldNotCreateDatabaseInMemoryException::CouldNotCreateDatabaseInMemoryException(std::string const & errorMessage)
	: CouldNotCreateDatabaseException(errorMessage)
{}


CouldNotCreateDatabaseTableException::CouldNotCreateDatabaseTableException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}


CouldNotAddContactException::CouldNotAddContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

CouldNotSearchForTheContactException::CouldNotSearchForTheContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}


CouldNotUpdateContactException::CouldNotUpdateContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

CouldNotDeleteContactException::CouldNotDeleteContactException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}


NonMatchingDependencyTypeException::NonMatchingDependencyTypeException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}

