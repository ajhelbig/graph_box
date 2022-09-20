#include "base_graph.hpp"

Node::Node(int xpos, int ypos, float radius) : x{xpos}, y{ypos}, rad{radius}, visited{false} {}

void Node::drawNode()
{
	DrawCircle(this->x, this->y, this->rad, RED);
}

void Node::drawEdges(bool solved)
{
	//edges will be redrawn
	//optimization for later
	if(solved)
		for(auto neighbor : this->solved_adjLis)
			DrawLine(this->x, this->y, neighbor->x, neighbor->y, RED);

	else
		for(auto neighbor : this->adjLis)
			DrawLine(this->x, this->y, neighbor->x, neighbor->y, GRAY);

}

void Graph::drawGraph()
{
	for(auto row : this->nodes)
		for(auto node : row)
			node.drawEdges(this->solved);
			
	for(auto row : this->nodes)
		for(auto node : row)
			node.drawNode();
}

double dist(const Node n1, const Node n2)
{
	return std::sqrt( ( (n1.x - n2.x) * (n1.x - n2.x) ) + ( (n1.y - n2.y) * (n1.y - n2.y) ) );
}

std::pair<double, Node*> findNN(Node &node)
{	
	Node* nearestNode = nullptr;
	double shortest_dist = std::numeric_limits<double>::infinity();

	for(int i = 0; i < node.adjLis.size(); ++i)
	{
		if(node.adjLis[i]->visited)
			continue;

		double dist_to_neighbor = dist( node, *node.adjLis[i] );

		if(dist_to_neighbor < shortest_dist)
		{
			nearestNode = node.adjLis[i];
			shortest_dist = dist_to_neighbor;
		}
	}

	return std::pair<double, Node*> (shortest_dist, nearestNode);
}

void Graph::findMST()
{
	std::vector<Node*> mst;

	this->nodes[0][0].visited = true;
	mst.push_back(&this->nodes[0][0]);

	while(true)
	{

		if( mst.size() == (nodes.size() * nodes[0].size()) )
			break;

		//finding the node nearest the mst
		Node *nearestNode = nullptr;
		Node *nodeNearest = nullptr;
		double shortest_dist = std::numeric_limits<double>::infinity();
		
		for(int i = 0; i < mst.size(); ++i)
		{	
			
			std::pair<double, Node*> NN (findNN(*mst[i]));

			if(NN.first < shortest_dist)
			{	
				shortest_dist = NN.first;
				nearestNode = NN.second;
				nodeNearest = mst[i];
			}
		}

		nearestNode->visited = true;
		mst.push_back(nearestNode);

		nodeNearest->solved_adjLis.push_back(nearestNode);
	}

	this->solved = true;
}
