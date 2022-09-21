#pragma once

#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cmath>
#include "raylib.h"

//base class for node
class Node
{
public:

	int x;
	int y;
	float rad;
	bool visited;

	std::vector<Node*> adjLis;
	std::vector<Node*> solved_adjLis;

	void drawNode();
	void drawEdges(bool solved);

	Node(int xpos, int ypos, float radius);
};

//base class for graph
class Graph
{
public:

	bool solved = false;
	int numNodes = 0;
	int seed = 0;

	std::vector<std::vector<Node>> nodes;

	void drawGraph(bool draw_both = true);

	std::pair<double, Node*> findNN(Node &node);

	void findMST(bool shuffle_tree = false);

};