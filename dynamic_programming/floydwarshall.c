// Floyd-Warshall Algorithm implementation in C (with comments)

#include <stdio.h>

#define V 4          // Number of vertices in the graph
#define INF 99999    // Representation of infinite distance (no direct edge)

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int dist[][V])
{
    int i, j, k;

    // k is the intermediate vertex
    // i is the source vertex
    // j is the destination vertex

    // The main triple nested loop to update the shortest distances
    for (k = 0; k < V; k++) {                // Pick all vertices as intermediate one by one
        for (i = 0; i < V; i++) {            // Pick all vertices as source one by one
            for (j = 0; j < V; j++) {        // Pick all vertices as destination one by one

                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist);
}

// Function to print the distance matrix
void printSolution(int dist[][V])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");   // Print INF if no path exists
            else
                printf("%7d", dist[i][j]);  // Print the distance
        }
        printf("\n");
    }
}

int main()
{
    // Define the adjacency matrix of the graph
    // graph[i][j] = weight of edge from i to j
    // INF means no direct edge
    int graph[V][V] = { 
                        { 0,    5,  INF,  10 },
                        { INF,  0,   3,  INF },
                        { INF, INF,  0,   1  },
                        { INF, INF, INF,  0  } 
                      };

    // Call the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}
