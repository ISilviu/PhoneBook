#pragma once

#include "IPluginSpecification.h"

#include <array>

namespace
{
	inline constexpr auto dependenci = std::array
	{
		std::string_view{"class InMemorySQLiteStoragePluginSpecification"}
	};
};

class UiPluginSpecification : public IPluginSpecification
{
public:
	IPlugin* create(std::vector<IPlugin*> const& dependencies = std::vector<IPlugin*>()) override;

	std::vector<std::string> getDependencies() const noexcept override;

private:
	const std::vector<std::string> _dependencies{ dependenci.cbegin(), dependenci.cend() };
};

