// Bellman-Ford Algorithm implementation in C (with comments)

#include <stdio.h>
#include <limits.h>

#define V 5   // Number of vertices in the graph
#define E 8   // Number of edges in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Utility function to print the distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t Infinity (unreachable)\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}

// Function that implements Bellman-Ford algorithm
// edge[]: array of edges
// src: source vertex
void BellmanFord(struct Edge edge[], int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as infinite
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;  // Distance to source is 0

    // Step 2: Relax all edges |V| - 1 times
    // A simple shortest path from source to any other vertex can have at most |V| - 1 edges
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;
            // If the distance to u is not INT_MAX and can be minimized, update dist[v]
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    // If we can still relax any edge, then there is a negative cycle
    for (int i = 0; i < E; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        int weight = edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    // Print the final distances
    printSolution(dist);
}

int main() {
    // Graph definition (edge list)
    // Each edge has source, destination, and weight
    struct Edge edge[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    // Run Bellman-Ford algorithm from source vertex 0
    BellmanFord(edge, 0);

    return 0;
}
