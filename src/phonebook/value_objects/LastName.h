#pragma once

#include <qstring.h>

class LastName
{
public:
	LastName(QString const& lastName);

	constexpr auto get() const noexcept->QString const&;

private:
	auto validate() const -> void;

	QString _lastName;
};

inline constexpr auto LastName::get() const noexcept -> QString const &
{
	return _lastName;
}


