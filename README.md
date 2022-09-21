# graph_box
Graphs, graph algorithms and graph visualizations all in one sandbox.

## Implemented in the project so far:
- ### Grid graph generator:
  - Generates an NxM graph with node x,y coordinates based on the width and height of the window divided by the desired spacing. 
  - Each nodes adjacency list is populated in one of 9 configurations 4 corner cases(2 neighbors), 4 edge cases(3 neighbors) and 1 middle case(4 neighbors).

- ### Complete graph generator:
  - Generates an N node graph with node x,y coordinates corresponding to points on an N-gon or random non-repeating x,y coordinates within the windows height and width.
  - Each nodes adjacency list is populated with every other node in the graph.
  
- ### Naive Minimum Spanning Tree Solver (O(N^3) - Ω(N^2))
  - Implemented as a method of the base graph class allows the findMST() function to be used on any of the above generated graphs.
