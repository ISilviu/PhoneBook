#include "PhoneBook.h"

void PhoneBook::add(ContactId const & id, Contact const & contact)
{
	_contacts.insert(std::make_pair(id, contact));
}

void PhoneBook::add(std::pair<ContactId, Contact> const & contact)
{
	_contacts.insert(contact);
}
