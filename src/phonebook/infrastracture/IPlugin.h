#pragma once
#include <vector>

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	virtual int run() = 0;
};