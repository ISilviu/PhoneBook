#include "Contact.h"

Contact::Contact(QString const & lastName, QString const & firstName, QString const & phoneNumber) noexcept
	:_lastName(lastName),
	_firstName(firstName),
	_phoneNumber(phoneNumber)
{}



Contact::Contact(LastName const & lastName, FirstName const & firstName, PhoneNumber const & phoneNumber) noexcept
	: _lastName(lastName.get()),
	_firstName(firstName.get()),
	_phoneNumber(phoneNumber.get())
{}


auto Contact::isEmpty() const noexcept -> bool
{
	return (_lastName.isEmpty() && _firstName.isEmpty() && _phoneNumber.isEmpty());
}