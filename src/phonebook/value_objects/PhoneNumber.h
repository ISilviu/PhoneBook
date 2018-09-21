#pragma once

#include <qstring.h>

class PhoneNumber
{
public:
	PhoneNumber(QString const& phoneNumber);

	constexpr auto get() const noexcept->QString const&;

private:
	auto validate() const -> void;

	QString _phoneNumber;
};

inline constexpr auto PhoneNumber::get() const noexcept -> QString const &
{
	return _phoneNumber;
}
