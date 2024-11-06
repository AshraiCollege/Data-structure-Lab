#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    char name[50];
    int id;
} City;

int graph[MAX_VERTICES][MAX_VERTICES];
City cities[MAX_VERTICES];

void createGraph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

void addEdge(int i, int j, int weight) {
    graph[i][j] = weight;
    graph[j][i] = weight;
}

void printGraph(int n) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void warshallAlgorithm(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void printShortestPath(int source, int destination) {
    printf("Shortest path from %s to %s: ", cities[source].name, cities[destination].name);
    if (graph[source][destination] == INT_MAX) {
        printf("No path exists.\n");
    } else {
        // Implement path reconstruction using backtracking
        // ...
    }
}

int main() {
    int n, i, j, weight;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    createGraph(n);

    // Read city information
    for (i = 0; i < n; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
    }

    printf("Enter edges (source, destination, weight):\n");
    while (scanf("%d %d %d", &i, &j, &weight) == 3) {
        addEdge(i, j, weight);
    }

    printGraph(n);
    warshallAlgorithm(n);

    printf("Enter source and destination cities (IDs): ");
    scanf("%d %d", &i, &j);
    printShortestPath(i, j);

    return 0;
}
