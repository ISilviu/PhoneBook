#pragma once

class IPlugin
{
public:
	virtual ~IPlugin() = default;

	virtual int run() = 0;
};