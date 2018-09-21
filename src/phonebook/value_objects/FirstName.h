#pragma once

#include <qstring.h>

class FirstName
{
public:
	FirstName(QString const& firstName);

	constexpr auto get() const noexcept->QString const&;

private:
	auto validate() const -> void;

	QString _firstName;
};

inline constexpr auto FirstName::get() const noexcept -> QString const &
{
	return _firstName;
}

