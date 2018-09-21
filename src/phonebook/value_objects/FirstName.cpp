#include "FirstName.h"

#include <regex>

#include "Exceptions.h"

FirstName::FirstName(QString const & firstName)
	:_firstName(firstName)
{
}

auto FirstName::validate() const -> void
{
	static std::regex const nameRegex("^[a-z'-a-z]+");

	if (!std::regex_match(_firstName.toStdString(), nameRegex))
		throw InvalidNameException("The provided name is not valid.");
}
