#pragma once

#include <unordered_map>

#include "Contact.h"
#include "ContactId.h"

namespace std
{
	template <> struct hash<ContactId>
	{
		constexpr std::size_t operator()(ContactId const& id) const noexcept
		{
			return std::hash<int>{}(id.get());
		}
	};
}

class PhoneBook
{
public:
	PhoneBook() = default;

	void add(ContactId const& id, Contact const& contact);
	void add(std::pair<ContactId, Contact> const& contact);

private:
	std::unordered_map<ContactId, Contact> _contacts;
};

