#include "complete_graph.hpp"

void Complete_Graph::buildNGon(std::vector<std::pair<int,int>> &coords)
{
	int radius = ( std::min(this->swidth, this->sheight) / 2 ) - ( 2 * this->dim );

	double angle = (360.0 / this->numNodes);
	double rotate = 0.0;
	
	for(int i = 0; i < this->numNodes; ++i)
	{
		double x = ( ( this->swidth / 2 ) - ( radius * sin(rotate * (PI / 180)) ) );
		double y = ( ( this->sheight / 2 ) - ( radius * cos(rotate * (PI / 180)) ) );

		double roundx = ( x - (int)x );
		double roundy = ( y - (int)y );

		if(roundx >= 0.5) x = std::ceil(x);
		else x = std::floor(x);

		if(roundy >= 0.5) y = std::ceil(y);
		else y = std::floor(y);

		coords.emplace_back( x, y );

		rotate += angle;
	}

}

void Complete_Graph::buildRandom(std::vector<std::pair<int, int>> &coords)
{
	int width = ( this->swidth / this->dim );
	int height = ( this->sheight / this->dim );

	this->numNodes %= (width * height);

	//creating all possible pairs to choose from
	for(int i = 0; i < width; ++i)
		for(int j = 0; j < height; ++j)
			coords.emplace_back(i * dim, j * dim);

	std::srand(this->seed);
	std::random_shuffle(coords.begin(), coords.end());

}

void Complete_Graph::buildGraph(std::vector<std::pair<int, int>> &coords)
{
	//populating the graph with nodes
	this->nodes.emplace_back();

	for(int i = 0; i < this->numNodes; ++i)
		this->nodes[0].emplace_back(coords[i].first, coords[i].second, radius);

	//filling adjacency matrix
	for(int i = 0; i < this->numNodes; ++i)
		for(int j = 0; j < this->numNodes; ++j)
			if(j != i)
				this->nodes[0][i].adjLis.push_back(&this->nodes[0][j]);
}

Complete_Graph::Complete_Graph(const int swidth, const int sheight, int dim, float radius, bool ngon, int seed, int numNodes) : swidth{swidth}, sheight{sheight}, dim{dim}, radius{radius}, ngon{ngon}
{

	this->numNodes = numNodes;
	this->seed = seed;
	
	std::vector<std::pair<int,int>> coords;
	
	switch(this->ngon)
	{
		case true:

		this->buildNGon(coords);

		break;

		case false:

		this->buildRandom(coords);

		break;
	}

	this->buildGraph(coords);
}