#pragma once

#include <QString>

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"

class Contact
{
public:
	Contact() = default;

	Contact(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept;

	Contact(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) noexcept;
	
	constexpr auto lastName() const noexcept->QString const&;

	constexpr auto firstName() const noexcept->QString const&;

	constexpr auto phoneNumber() const noexcept->QString const&;

	auto isEmpty() const noexcept -> bool;

private:
	QString _lastName;

	QString _firstName;

	QString _phoneNumber;
};

inline constexpr auto Contact::lastName() const noexcept -> QString const&
{
	return _lastName;
}

inline constexpr auto Contact::firstName() const noexcept -> QString const&
{
	return _firstName;
}

inline constexpr auto Contact::phoneNumber() const noexcept -> QString const&
{
	return _phoneNumber;
}



