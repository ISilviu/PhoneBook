#include "ContactId.h"

#include <regex>

#include "Exceptions.h"


ContactId::ContactId(int const id)
	:_id(id)
{
	validate();
}

auto ContactId::validate() const -> void
{
	static std::regex const idRegex("^[0-9]+$");

	if (!std::regex_match(std::to_string(_id), idRegex))
		throw InvalidContactId("This contact id is invalid.");
}
