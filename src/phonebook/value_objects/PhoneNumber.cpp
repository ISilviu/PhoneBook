#include "PhoneNumber.h"

#include <regex>

#include "Exceptions.h"

PhoneNumber::PhoneNumber(std::string_view phoneNumber)
	: _phoneNumber(phoneNumber)
{
	validate();
}

auto PhoneNumber::validate() const -> void
{
	static std::regex const phoneNumberRegex("^[0-9]+$");

	if (!std::regex_match(_phoneNumber, phoneNumberRegex))
		throw InvalidPhoneNumberException("The provided phone number is invalid.");
}
