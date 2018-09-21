#include "LastName.h"

#include <regex>

#include "Exceptions.h"

LastName::LastName(QString const & lastName)
	:_lastName(lastName)
{
	validate();
}


auto LastName::validate() const -> void
{
	static std::regex const nameRegex("^[a-z'-a-z]+");

	if (!std::regex_match(_lastName.toStdString(), nameRegex))
		throw InvalidNameException("The provided name is not valid.");
}
