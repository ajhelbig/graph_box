#include "graph.hpp"

int main(void)
{

    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Graphs...");

    SetTargetFPS(1);

    //Complete_Graph g(screenWidth, screenHeight, 10, 5.0, 6, 11, true);

    //int seed = 1;
    int numNodes = 1;

    while (!WindowShouldClose())
    {
        Complete_Graph g(screenWidth, screenHeight, 10, 5.0, 0, numNodes, true);

        BeginDrawing();

            ClearBackground(BLACK);

            //DrawFPS(0,0);

            g.drawGraph();

        EndDrawing();

        //++seed;
        ++numNodes;
    }

    CloseWindow();

    return 0;
}
