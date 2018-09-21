#pragma once

#include <string>

class FirstName
{
public:
	FirstName(std::string_view firstName);

	constexpr auto get() const noexcept->std::string const&;

private:
	auto validate() const -> void;

	std::string _firstName;
};

inline constexpr auto FirstName::get() const noexcept -> std::string const &
{
	return _firstName;
}

