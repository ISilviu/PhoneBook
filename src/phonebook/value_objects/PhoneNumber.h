#pragma once

#include <string>

class PhoneNumber
{
public:
	PhoneNumber(std::string_view phoneNumber);

	constexpr auto get() const noexcept->std::string const&;

private:
	auto validate() const -> void;

	std::string _phoneNumber;
};

inline constexpr auto PhoneNumber::get() const noexcept -> std::string const &
{
	return _phoneNumber;
}
