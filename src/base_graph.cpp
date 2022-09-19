#include "base_graph.hpp"

Node::Node(int xpos, int ypos, float radius) : x{xpos}, y{ypos}, rad{radius} {}

void Node::drawNode()
{
	DrawCircle(this->x, this->y, this->rad, RED);
}

void Node::drawEdges()
{
	//edges will be redrawn
	//optimization for later
	for(auto neighbor : this->adjLis)
				DrawLine(this->x, this->y, neighbor->x, neighbor->y, WHITE);
}

void Graph::drawGraph()
{
	for(auto row : this->nodes)
		for(auto node : row)
			node.drawEdges();
			
	for(auto row : this->nodes)
		for(auto node : row)
			node.drawNode();
}