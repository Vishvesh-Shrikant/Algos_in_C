    // Prim's Minimum Spanning Tree (MST) algorithm (Adjacency Matrix)

    #include <limits.h>
    #include <stdbool.h>
    #include <stdio.h>

    #define V 5 // Total number of vertices

    // Find vertex with smallest key not in MST
    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }
    
    // Print MST edges and their weights
    int printMST(int parent[], int graph[V][V]) {
        printf("Edge \tWeight\n");
        for (int i = 1; i < V; i++)
            printf("%d - %d \t%d\n", parent[i], i, graph[parent[i]][i]);
    }

    // Construct and print MST using Prim's algorithm
    void primMST(int graph[V][V]) {
        int parent[V];  // Stores MST structure
        int key[V];     // Minimum edge weights
        bool mstSet[V]; // Track included vertices

        // Initialize keys as ∞ and MST set as false
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        key[0] = 0;       // Start from vertex 0
        parent[0] = -1;   // Root of MST

        // Loop to construct MST with V vertices
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet); // Pick min key vertex
            mstSet[u] = true;            // Include in MST

            // Update keys and parents of adjacent vertices
            for (int v = 0; v < V; v++)
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
        }

        printMST(parent, graph); // Output MST
    }

    // Main function
    int main() {
        // Graph as adjacency matrix
        int graph[V][V] = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };

        primMST(graph); // Call MST function
        return 0;
    }
