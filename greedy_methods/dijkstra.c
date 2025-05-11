// Dijkstra's Algorithm Implementation in C (with comments)

#include <stdio.h>
#include <limits.h>

#define V 6  // Number of vertices in the graph

int graph[V][V], src;  // Graph adjacency matrix and source node

// Function to print the shortest distances from source to all vertices
void printDistance(int dist[]) {
    int i;
    for (i = 0; i < V; i++) {
        printf("Distance from source %d to destination %d : ", src, i);
        if (dist[i] == INT_MAX)
            printf("Infinity (unreachable)\n");
        else
            printf("%d\n", dist[i]);
    }
}

// Function to find the vertex with the minimum distance value from
// the set of vertices not yet processed
int minDistance(int dist[], int visited[]) {
    int i, min = INT_MAX, min_idx = -1;

    for (i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

// Function that implements Dijkstra's algorithm
void dijkstra() {
    int dist[V], visited[V];
    int i, u, v;

    // Initialize all distances as infinity and visited[] as false
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance to the source is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (i = 0; i < V - 1; i++) {
        // Select the unvisited vertex with the smallest distance
        u = minDistance(dist, visited);
        if (u == -1)  // No more reachable vertices
            break;
        visited[u] = 1;

        // Update dist[] of adjacent vertices of the picked vertex
        for (v = 0; v < V; v++) {
            // Update dist[v] if:
            // 1. There is an edge from u to v (graph[u][v] != 0 or INT_MAX)
            // 2. Vertex v is not visited
            // 3. Total weight of path from src to v through u is smaller than current value of dist[v]
            if (visited[v] == 0 && graph[u][v] != INT_MAX && dist[u] != INT_MAX &&
                (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printDistance(dist);
}

// Function to input the adjacency matrix
void input_graph() {
    int u, v;
    printf("\nEnter the adjacency matrix (6x6):\n");
    printf("Note: if there is no direct edge between two nodes, enter 1000\n");

    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            scanf("%d", &graph[u][v]);
            // Convert large number (representing no edge) to INT_MAX
            if (graph[u][v] >= 1000) {
                graph[u][v] = INT_MAX;
            }
        }
    }
}

int main() {
    input_graph();

    // Input a valid source node
    do {
        printf("\nEnter source node (0 to %d): ", V - 1);
        scanf("%d", &src);
        if (src < 0 || src >= V) {
            printf("Invalid source node. Please enter a valid node index.\n");
        }
    } while (src < 0 || src >= V);

    // Run Dijkstra's algorithm
    dijkstra();

    return 0;
}
