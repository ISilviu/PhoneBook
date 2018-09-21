#pragma once

#include <stdexcept>

class CouldNotOpenDatabaseException : public std::runtime_error
{
public:
	CouldNotOpenDatabaseException(std::string_view errorMessage);
};

class CouldNotCreateDatabaseException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseException(std::string_view errorMessage);
};

class CouldNotCreateDatabaseInMemoryException : public CouldNotCreateDatabaseException
{
public:
	CouldNotCreateDatabaseInMemoryException(std::string_view errorMessage);
};

class CouldNotCreateDatabaseTableException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseTableException(std::string_view errorMessage);
};

class CouldNotAddContactException : public std::runtime_error
{
public:
	CouldNotAddContactException (std::string_view errorMessage);
};

class CouldNotSearchForTheContactException : public std::runtime_error
{
public:
	CouldNotSearchForTheContactException(std::string_view errorMessage);
};

class CouldNotUpdateContactException : public std::runtime_error
{
public:
	CouldNotUpdateContactException(std::string_view errorMessage);
};

class CouldNotDeleteContactException : public std::runtime_error
{
public:
	CouldNotDeleteContactException(std::string_view errorMessage);
};

class NonMatchingDependencyTypeException : public std::runtime_error
{
public:
	NonMatchingDependencyTypeException(std::string_view errorMessage);
};

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



