#pragma once

#include <string>

class LastName
{
public:
	LastName(std::string_view lastName);

	constexpr auto get() const noexcept->std::string const&;

private:
	auto validate() const -> void;

	std::string _lastName;
};

inline constexpr auto LastName::get() const noexcept -> std::string const &
{
	return _lastName;
}


