#include "DomainModelSpecificExceptions.h"

InvalidNameException::InvalidNameException(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}

InvalidPhoneNumberException::InvalidPhoneNumberException(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}

InvalidContactId::InvalidContactId(std::string_view errorMessage)
	: std::domain_error(errorMessage.data())
{}
