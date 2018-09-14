#include "Exceptions.h"

CouldNotOpenDatabaseException::CouldNotOpenDatabaseException(std::string const& errorMessage)
	:std::runtime_error(errorMessage)
{}

const char* CouldNotOpenDatabaseException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotCreateDatabaseException::CouldNotCreateDatabaseException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

const char* CouldNotCreateDatabaseException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotCreateDatabaseInMemoryException::CouldNotCreateDatabaseInMemoryException(std::string const & errorMessage)
	: CouldNotCreateDatabaseException(errorMessage)
{}

const char* CouldNotCreateDatabaseInMemoryException::what() const noexcept
{
	return CouldNotCreateDatabaseException::what();
}

CouldNotCreateDatabaseTableException::CouldNotCreateDatabaseTableException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}

const char * CouldNotCreateDatabaseTableException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotAddContactException::CouldNotAddContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

const char * CouldNotAddContactException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotSearchForTheContactException::CouldNotSearchForTheContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

const char * CouldNotSearchForTheContactException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotUpdateContactException::CouldNotUpdateContactException(std::string const& errorMessage)
	: std::runtime_error(errorMessage)
{}

const char * CouldNotUpdateContactException::what() const noexcept
{
	return std::runtime_error::what();
}

CouldNotDeleteContactException::CouldNotDeleteContactException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}

const char * CouldNotDeleteContactException::what() const noexcept
{
	return std::runtime_error::what();
}

NonMatchingDependencyTypeException::NonMatchingDependencyTypeException(std::string const & errorMessage)
	: std::runtime_error(errorMessage)
{}
const char * NonMatchingDependencyTypeException::what() const noexcept
{
	return std::runtime_error::what();
}
