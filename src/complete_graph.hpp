#pragma once

#include "base_graph.hpp"

class Complete_Graph: public Graph
{
public:

	const int swidth;
	const int sheight;
	int dim;
	float radius;
	int seed;
	int numNodes;
	bool ngon;

	void buildNGon(std::vector<std::pair<int,int>> &coords);

	void buildRandom(std::vector<std::pair<int,int>> &coords);

	void buildGraph(std::vector<std::pair<int, int>> &coords);

	Complete_Graph(const int swidth, const int sheight, int numNodes, float radius, int seed, int dim, bool ngon);
};