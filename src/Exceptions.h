#pragma once

#include <stdexcept>

class CouldNotOpenDatabaseException : public std::runtime_error
{
public:
	CouldNotOpenDatabaseException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotCreateDatabaseException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotCreateDatabaseInMemoryException : public CouldNotCreateDatabaseException
{
public:
	CouldNotCreateDatabaseInMemoryException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotCreateDatabaseTableException : public std::runtime_error
{
public:
	CouldNotCreateDatabaseTableException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotAddContactException : public std::runtime_error
{
public:
	CouldNotAddContactException (std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotSearchForTheContactException : public std::runtime_error
{
public:
	CouldNotSearchForTheContactException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotUpdateContactException : public std::runtime_error
{
public:
	CouldNotUpdateContactException(std::string const& errorMessage);
	const char* what() const noexcept;
};

class CouldNotDeleteContactException : public std::runtime_error
{
public:
	CouldNotDeleteContactException(std::string const& errorMessage);
	const char* what() const noexcept;
};





