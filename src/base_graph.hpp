#pragma once

#include <iostream>
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

	std::vector<Node*> adjLis;

	void drawNode();
	void drawEdges();

	Node(int xpos, int ypos, float radius);
};

//base class for graph
class Graph
{
public:

	std::vector<std::vector<Node>> nodes;

	void drawGraph();

};