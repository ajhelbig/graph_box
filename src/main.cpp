#include "graph.hpp"

int main(void)
{

    const int screenWidth = 500;
    const int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Graphs...");

    SetTargetFPS(1);

    int seed = 1;

    while (!WindowShouldClose())
    {
        //Complete_Graph g1(screenWidth, screenHeight, 10, 5.0, true, seed, 8);
        Grid_Graph g1(screenWidth, screenHeight, 100, 5.0);


        g1.findMST(true);

        BeginDrawing();

            ClearBackground(BLACK);

            g1.drawGraph(false);

        EndDrawing();

        ++seed;
    }

    CloseWindow();

    return 0;
}
