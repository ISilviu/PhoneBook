#include "LastName.h"

#include <regex>

#include "DomainModelSpecificExceptions.h"

LastName::LastName(std::string_view lastName)
	:_lastName(lastName)
{
	validate();
}


auto LastName::validate() const -> void
{
	static std::regex const nameRegex("^[a-zA-Z-']+$");

	if (!std::regex_match(_lastName, nameRegex))
		throw InvalidNameException("The provided name is not valid.");
}
