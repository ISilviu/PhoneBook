#include "Contact.h"

Contact::Contact(LastName const & lastName, FirstName const & firstName, PhoneNumber const & phoneNumber) noexcept
	: _lastName(lastName.get()),
	_firstName(firstName.get()),
	_phoneNumber(phoneNumber.get())
{}


auto Contact::isEmpty() const noexcept -> bool
{
	return (_lastName.empty() && _firstName.empty() && _phoneNumber.empty());
}