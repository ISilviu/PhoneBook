#pragma once
#include <vector>

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	virtual std::vector<std::string> getDependencies() const = 0;

	virtual void init(std::vector<IPlugin*> const& dependencies) = 0;

	virtual void init() = 0;

	virtual int run() = 0;
};