#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

// Function to print the color assignments of vertices
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}

// Function to check whether it's safe to color vertex 'v' with color 'c'
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        // Check if the adjacent vertex has the same color
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;  // No conflicts, safe to assign color
}

// Recursive utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color, return true
    if (v == V)
        return true;

    // Try all colors from 1 to m for the current vertex 'v'
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color 'c' to vertex 'v' is safe
        if (isSafe(v, graph, color, c)) {
            color[v] = c;  // Assign color

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If it doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Main function to initialize color array and start coloring process
bool graphColoring(bool graph[V][V], int m) {
    int color[V];

    // Initialize all vertices with 0 (no color assigned)
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive utility to solve the problem
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
        return false;
    }

    // If coloring is possible, print the color assignments
    printSolution(color);
    return true;
}

// Driver code
int main() {
    // Adjacency matrix representation of the graph
    bool graph[V][V] = {
        {0, 1, 1, 1},  // Vertex 0 is connected to 1, 2, 3
        {1, 0, 1, 0},  // Vertex 1 is connected to 0, 2
        {1, 1, 0, 1},  // Vertex 2 is connected to 0, 1, 3
        {1, 0, 1, 0}   // Vertex 3 is connected to 0, 2
    };

    int m = 3;  // Number of colors available

    // Call the coloring function
    graphColoring(graph, m);

    return 0;
}
