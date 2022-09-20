#include "graph.hpp"

int main(void)
{

    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Graphs...");

    SetTargetFPS(1);

    Complete_Graph g1(screenWidth, screenHeight, 10, 5.0, 2, 7, false);
    Complete_Graph g2(screenWidth, screenHeight, 10, 5.0, 2, 7, false);

    // Grid_Graph g1(screenWidth, screenHeight, 50, 5.0);
    // Grid_Graph g2(screenWidth, screenHeight, 50, 5.0);

    g1.findMST();

    //int seed = 1;
    //int numNodes = 1;

    while (!WindowShouldClose())
    {
        //Complete_Graph g(screenWidth, screenHeight, 10, 5.0, 0, numNodes, true);

        BeginDrawing();

            ClearBackground(BLACK);

            //DrawFPS(0,0);

            g2.drawGraph();

            g1.drawGraph();

        EndDrawing();

        //++seed;
        //if(++numNodes > 16) numNodes = 1;
    }

    CloseWindow();

    return 0;
}
