#include "FirstName.h"

#include <regex>

#include "Exceptions.h"

FirstName::FirstName(std::string_view firstName)
	:_firstName(firstName)
{
	validate();
}

auto FirstName::validate() const -> void
{
	static std::regex const nameRegex("^[a-z'-a-z]+");

	if (!std::regex_match(_firstName, nameRegex))
		throw InvalidNameException("The provided name is not valid.");
}
