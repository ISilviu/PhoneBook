#pragma once
#include <vector>

enum class Dependency;

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	virtual std::vector<Dependency> getDependencies() const = 0;

	virtual void init(std::vector<Dependency> const& dependencies) = 0;

	virtual void run() = 0;

	virtual void shutDown() = 0;
};