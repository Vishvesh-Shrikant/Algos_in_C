#include <stdio.h>

#define V 5  // Number of vertices in the graph

// Sample Graph 1: Has a Hamiltonian Cycle
int graph1[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

// Sample Graph 2: Does NOT have a Hamiltonian Cycle
int graph2[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

int path[V];  // Stores the current path of vertices in the cycle

// Function to check if vertex 'v' can be added to position 'pos' in the Hamiltonian Cycle
int isSafe(int v, int graph[V][V], int pos)
{
    // Check if there is an edge from the previous vertex to vertex 'v'
    if (!graph[path[pos - 1]][v])
        return 0;

    // Check if the vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;  // Safe to include
}

// Recursive function to build the Hamiltonian Cycle
int hamCycleUtil(int graph[V][V], int pos)
{
    // Base Case: All vertices are included in the path
    if (pos == V)
        return graph[path[pos - 1]][path[0]];  // Return 1 if there's an edge from last to first vertex

    // Try different vertices as the next candidate in the cycle
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, pos)) {
            path[pos] = v;  // Add vertex to path

            // Recur to construct rest of the path
            if (hamCycleUtil(graph, pos + 1))
                return 1;

            path[pos] = -1;  // Backtrack if adding vertex v doesn't lead to a solution
        }
    }

    return 0;  // No valid vertex found for this position
}

// Utility function to print the solution path
void printSolution() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);  // Print starting vertex again to complete the cycle
}

// Function that solves the Hamiltonian Cycle problem using backtracking
void solveHamiltonianCycle(int graph[V][V]) {
    // Initialize all positions in the path to -1
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Start at vertex 0

    // Start recursive search from position 1
    if (hamCycleUtil(graph, 1))
        printSolution();
    else
        printf("No Hamiltonian Cycle exists.\n");
}

// Driver Code
int main() {
    printf("Graph 1:\n");
    solveHamiltonianCycle(graph1);

    printf("\nGraph 2:\n");
    solveHamiltonianCycle(graph2);

    return 0;
}
