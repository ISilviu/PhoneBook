#pragma once

#include <QString>

class Contact
{
public:
	constexpr Contact(QString const& lastName, QString const& firstName, QString const& phoneNumber);

	constexpr auto lastName() const noexcept->QString const&;

	constexpr auto firstName() const noexcept->QString const&;

	constexpr auto phoneNumber() const noexcept->QString const&;


private:
	QString _lastName;

	QString _firstName;

	QString _phoneNumber;
};

inline constexpr Contact::Contact(QString const & lastName, QString const & firstName, QString const & phoneNumber)
	:_lastName(lastName),
	_firstName(firstName),
	_phoneNumber(phoneNumber)
{}

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


