#pragma once

#include <stdexcept>


class NonMatchingDependencyTypeException : public std::runtime_error
{
public:
	NonMatchingDependencyTypeException(std::string_view errorMessage);
};

