#include "CouldNotOpenDatabaseException.h"

CouldNotOpenDatabaseException::CouldNotOpenDatabaseException(std::string const& errorMessage)
	:std::runtime_error(errorMessage)
{}

const char* CouldNotOpenDatabaseException::what() const noexcept
{
	return std::runtime_error::what();
}
