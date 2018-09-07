#pragma once

#include <stdexcept>

class CouldNotOpenDatabaseException : public std::runtime_error
{
public:
	CouldNotOpenDatabaseException(std::string const& errorMessage);
	const char* what() const noexcept;
};


