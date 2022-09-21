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
        Complete_Graph g1(screenWidth, screenHeight, 10, 5.0, seed, false, 7);

        g1.findMST();

        BeginDrawing();

            ClearBackground(BLACK);

            g1.drawGraph();

        EndDrawing();

        ++seed;
    }

    CloseWindow();

    return 0;
}
