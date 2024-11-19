#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **adjMatrix;
    int vertices;
    int directed;
} Graph;

Graph* createGraph(int vertices, int directed) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->directed = directed;
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v) {
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        printf("Invalid vertices.\n");
        return;
    }
    graph->adjMatrix[u][v] = 1;
    if (!graph->directed) {
        graph->adjMatrix[v][u] = 1;
    }
}

void removeEdge(Graph *graph, int u, int v) {
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        printf("Invalid vertices.\n");
        return;
    }
    graph->adjMatrix[u][v] = 0;
    if (!graph->directed) {
        graph->adjMatrix[v][u] = 0;
    }
}

int hasEdge(Graph *graph, int u, int v) {
    if (u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices) {
        printf("Invalid vertices.\n");
        return 0;
    }
    return graph->adjMatrix[u][v] == 1;
}

void displayGraph(Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void getNeighbors(Graph *graph, int u) {
    if (u < 0 || u >= graph->vertices) {
        printf("Invalid vertex.\n");
        return;
    }
    printf("Neighbors of vertex %d: ", u);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[u][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int degree(Graph *graph, int u) {
    if (u < 0 || u >= graph->vertices) {
        printf("Invalid vertex.\n");
        return -1;
    }
    int deg = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[u][i] == 1) {
            deg++;
        }
    }
    return deg;
}

void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    Graph *graph = createGraph(4, 0);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 0);
    displayGraph(graph);
    printf("\nEdge between 1 and 2: %d\n", hasEdge(graph, 1, 2));
    getNeighbors(graph, 1);
    printf("\nDegree of vertex 0: %d\n", degree(graph, 0));
    removeEdge(graph, 1, 2);
    printf("\nUpdated Adjacency Matrix after removing edge (1, 2):\n");
    displayGraph(graph);
    freeGraph(graph);
    return 0;
}

