#include "Graph.h"

#include <boost/graph/topological_sort.hpp>

auto Graph::topologicalSort() -> std::vector<int>
{
	std::vector<int> sorted;
	boost::topological_sort(_graph, std::back_inserter(sorted));

	return sorted;
}
