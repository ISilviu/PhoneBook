#include "Contact.h"

Contact::Contact(std::string_view lastName, std::string_view firstName, std::string_view phoneNumber) noexcept
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
	return (_lastName.empty() && _firstName.empty() && _phoneNumber.empty());
}