#pragma once

#include "base_graph.hpp"

class Grid_Graph: public Graph
{
public:

	Grid_Graph(const int swidth, const int sheight, int dim, float radius);
};
