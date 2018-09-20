#pragma once

#include <stdexcept>

class CouldNotOpenDatabaseException : public std::runtime_error
{
public:
	CouldNotOpenDatabaseException(std::string const& errorMessage);
};

class CouldNotCreateDatabaseException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseException(std::string const& errorMessage);
};

class CouldNotCreateDatabaseInMemoryException : public CouldNotCreateDatabaseException
{
public:
	CouldNotCreateDatabaseInMemoryException(std::string const& errorMessage);
};

class CouldNotCreateDatabaseTableException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseTableException(std::string const& errorMessage);
};

class CouldNotAddContactException : public std::runtime_error
{
public:
	CouldNotAddContactException (std::string const& errorMessage);
};

class CouldNotSearchForTheContactException : public std::runtime_error
{
public:
	CouldNotSearchForTheContactException(std::string const& errorMessage);
};

class CouldNotUpdateContactException : public std::runtime_error
{
public:
	CouldNotUpdateContactException(std::string const& errorMessage);
};

class CouldNotDeleteContactException : public std::runtime_error
{
public:
	CouldNotDeleteContactException(std::string const& errorMessage);
};

class NonMatchingDependencyTypeException : public std::runtime_error
{
public:
	NonMatchingDependencyTypeException(std::string const& errorMessage);
};





