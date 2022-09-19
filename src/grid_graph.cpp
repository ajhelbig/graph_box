#include "grid_graph.hpp"

Grid_Graph::Grid_Graph(const int swidth, const int sheight, int dim, float radius)
{

	int width = ( swidth / dim ) + dim;
	int height = ( sheight / dim ) + dim;

	this->nodes.reserve(height);

	//creating nodes
	for(int i = 0; i < height; ++i)
	{
		this->nodes.emplace_back();
		this->nodes[i].reserve(width);

		for(int j = 0; j < width; ++j)
		{
			this->nodes[i].emplace_back((j * dim), (i * dim), radius);
			this->nodes[i][j].adjLis.reserve(4);
		}

		
	}

	//populating adjacency lists
	for(int i = 0; i < height; ++i)
	{
		for(int j = 0; j < width; ++j)
		{

			if( i == 0 )
			{
				if( j == 0 )
				{
					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}

				else if( j == (width - 1) )
				{
					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );
				}

				else
				{
					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}
			}

			else if( i == (height - 1))
			{
				if( j == 0 )
				{
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}

				else if( j == (width - 1) )
				{
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );
				}

				else
				{
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}
			}

			else
			{
				if( j == 0 )
				{
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}

				else if ( j == (width - 1) )
				{
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );
				}

				else
				{	
					//add the node above
					this->nodes[i][j].adjLis.push_back( &this->nodes[i - 1][j] );

					//add the node below
					this->nodes[i][j].adjLis.push_back( &this->nodes[i + 1][j] );

					//add the node to the left
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j - 1] );

					//add the node to the right
					this->nodes[i][j].adjLis.push_back( &this->nodes[i][j + 1] );
				}
			}
		}
	}
}