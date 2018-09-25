#pragma once

#include <stdexcept>


class InvalidNameException : public std::domain_error
{
public:
	InvalidNameException(std::string_view errorMessage);
};

class InvalidPhoneNumberException : public std::domain_error
{
public:
	InvalidPhoneNumberException(std::string_view errorMessage);
};

class InvalidContactId : public std::domain_error
{
public:
	InvalidContactId(std::string_view errorMessage);
};

