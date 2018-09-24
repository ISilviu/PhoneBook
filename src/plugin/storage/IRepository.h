#pragma once

#include <vector>

template <typename T, typename Container>
class IRepository
{
public:
	virtual ~IRepository() = default;

	virtual void add(T const& item) = 0;

	virtual void remove(int const id) = 0;

	virtual void update(T const& newProperties, int const id) = 0;

	virtual Container const search(T const& item) = 0;

	virtual Container const listAll() = 0;
};


