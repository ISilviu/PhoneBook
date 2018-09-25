#pragma once
#include <vector>

enum class Dependency;

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	//virtual std::vector<IPlugin*> getDependencies() const = 0;

	virtual void init(std::vector<IPlugin*> const& dependencies) = 0;

	virtual void init() = 0;

	virtual int run() = 0;

	virtual void shutDown() = 0;
};