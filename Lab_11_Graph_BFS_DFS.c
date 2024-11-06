#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph {
    int adj[MAX][MAX];
    int numVertices;
} Graph;

// Function to create a graph with N cities
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;

    // Initialize adjacency matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge in the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1; // For directed graph
}

// Depth-First Search (DFS)
void DFS(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex); // Print the vertex

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Breadth-First Search (BFS)
void BFS(Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = 1; // Mark the start vertex as visited
    queue[rear++] = startVertex; // Enqueue the start vertex

    while (front < rear) {
        int currentVertex = queue[front++]; // Dequeue a vertex
        printf("%d ", currentVertex); // Print the vertex

        // Enqueue all the adjacent unvisited vertices
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark it visited
                queue[rear++] = i; // Enqueue it
            }
        }
    }
}

int main() {
    int n, edges, src, dest, startVertex;

    printf("Enter the number of cities (vertices): ");
    scanf("%d", &n);

    Graph* graph = createGraph(n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting city (vertex) for DFS: ");
    scanf("%d", &startVertex);

    int visited[MAX] = {0};
    printf("Nodes reachable from %d using DFS: ", startVertex);
    DFS(graph, startVertex, visited);
    printf("\n");

    printf("Enter the starting city (vertex) for BFS: ");
    scanf("%d", &startVertex);
    printf("Nodes reachable from %d using BFS: ", startVertex);
    BFS(graph, startVertex);
    printf("\n");

    // Free allocated memory
    free(graph);
    return 0;
}
