#pragma once

#include <boost/graph/adjacency_list.hpp>

#include <deque>

class Graph
{
public:
	template <typename InputIterator>
	Graph(int numberOfVertices, InputIterator first, InputIterator last);

	auto topologicalSort()->std::vector<int>;

private:
	boost::adjacency_list<> _graph;
};

template<typename InputIterator>
inline Graph::Graph(int numberOfVertices, InputIterator first, InputIterator last)
	: _graph(first, last, numberOfVertices)
{}