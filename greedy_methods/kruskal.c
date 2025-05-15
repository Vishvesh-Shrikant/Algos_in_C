#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Find the set (with path compression)
int find(int parent[], int i) {
	return (parent[i] == -1) ? i : (parent[i] = find(parent, parent[i]));
}

// Union of two sets
void Union(int parent[], int x, int y) {
	parent[find(parent, x)] = find(parent, y);
}

// Kruskal's MST function
void KruskalMST(int graph[][3], int V, int E) {
	int parent[V];
	for (int i = 0; i < V; i++) parent[i] = -1;

	// Sort edges by weight (bubble sort)
	for (int i = 0; i < E - 1; i++)
		for (int j = 0; j < E - i - 1; j++)
			if (graph[j][2] > graph[j + 1][2]) {
				for (int k = 0; k < 3; k++) {
					int tmp = graph[j][k];
					graph[j][k] = graph[j + 1][k];
					graph[j + 1][k] = tmp;
				}
			}

	printf("Edges in the MST:\n");
	int e = 0, i = 0;
	while (e < V - 1 && i < E) {
		int u = graph[i][0], v = graph[i][1], w = graph[i][2];
		if (find(parent, u) != find(parent, v)) 
		{
			printf("%d -- %d == %d\n", u, v, w);
			Union(parent, u, v);
			e++;
		}
		i++;
	}
}

int main() {
	int V = 4, E = 5;
	int graph[MAX][3] = {
		{0, 1, 10}, {0, 2, 6}, {0, 3, 5},
		{1, 3, 15}, {2, 3, 4}
	};

	KruskalMST(graph, V, E);
	return 0;
}
