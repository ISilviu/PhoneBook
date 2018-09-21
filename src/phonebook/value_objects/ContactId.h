#pragma once

class ContactId
{
public:
	ContactId(int const id);

	constexpr auto get() const noexcept->int const;

private:
	auto validate() const -> void;

	int _id;
};

inline constexpr auto ContactId::get() const noexcept -> int const
{
	return _id;
}

