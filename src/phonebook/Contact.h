#pragma once

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"

class Contact
{
public:
	Contact() = default;

	Contact(std::string_view lastName, std::string_view firstName, std::string_view phoneNumber) noexcept;

	Contact(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) noexcept;
	
	constexpr auto lastName() const noexcept->std::string const&;

	constexpr auto firstName() const noexcept->std::string  const&;

	constexpr auto phoneNumber() const noexcept->std::string  const&;

	auto isEmpty() const noexcept -> bool;

private:
	std::string _lastName;

	std::string _firstName;

	std::string _phoneNumber;
};

inline constexpr auto Contact::lastName() const noexcept -> std::string  const&
{
	return _lastName;
}

inline constexpr auto Contact::firstName() const noexcept -> std::string  const&
{
	return _firstName;
}

inline constexpr auto Contact::phoneNumber() const noexcept -> std::string  const&
{
	return _phoneNumber;
}



