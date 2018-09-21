#include "Exceptions.h"

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


NonMatchingDependencyTypeException::NonMatchingDependencyTypeException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}

InvalidNameException::InvalidNameException(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}

InvalidPhoneNumberException::InvalidPhoneNumberException(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}

InvalidContactId::InvalidContactId(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}
