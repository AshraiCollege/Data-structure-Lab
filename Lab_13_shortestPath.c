#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 100
#define INF INT_MAX

void initializeGraph(int graph[MAX_CITIES][MAX_CITIES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0; // Distance to itself is zero
            } else {
                graph[i][j] = INF; // Initialize other distances to infinity
            }
        }
    }
}

void addEdge(int graph[MAX_CITIES][MAX_CITIES], int u, int v, int weight) {
    graph[u][v] = weight; // For directed graph, set distance
    graph[v][u] = weight; // Uncomment for undirected graph
}

void printGraph(int graph[MAX_CITIES][MAX_CITIES], int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", graph[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[MAX_CITIES][MAX_CITIES], int n) {
    int dist[MAX_CITIES][MAX_CITIES];

    // Initialize distance array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Warshall's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest paths
    printf("Shortest distances between every pair of cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n, u, v, weight;
    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    initializeGraph(graph, n);

    // Add edges
    while (1) {
        printf("Enter edge (u v weight) or -1 to stop: ");
        scanf("%d", &u);
        if (u == -1) break;
        scanf("%d %d", &v, &weight);
        addEdge(graph, u, v, weight);
    }

    printGraph(graph, n);
    floydWarshall(graph, n);

    return 0;
}
