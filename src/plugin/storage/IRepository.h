#pragma once

#include <vector>

template <typename T>
class IRepository
{
public:
	virtual ~IRepository() = default;

	virtual void add(T const& item) = 0;

	virtual void remove(int const id) = 0;

	virtual void update(T const& newProperties, int const id) = 0;

	virtual std::vector<T> search(T const& item) = 0;

	virtual std::vector<T> listAll() = 0;
};


