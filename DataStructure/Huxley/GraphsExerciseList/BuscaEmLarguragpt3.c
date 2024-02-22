#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Queue {
    int* items;
    int front;
    int rear;
    int size;
} Queue;

typedef struct Graph {
    Node** adjList;
    int numVertices;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = NULL;

    // Se a lista adjacente estiver vazia, insira o novo nó como o primeiro nó
    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = newNode;
    } else {
        // Caso contrário, percorra a lista até o final e adicione o novo nó lá
        Node* temp = graph->adjList[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;

    return queue;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->size - 1)
        return;

    if (queue->front == -1)
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue* queue) {
    int item;

    if (isEmpty(queue))
        return -1;

    item = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    return item;
}

void bfs(Graph* graph, int startVertex, int endVertex, int testCase) {
    int* distance = (int*)malloc(graph->numVertices * sizeof(int));
    int* predecessor = (int*)malloc(graph->numVertices * sizeof(int));
    Queue* queue = createQueue(graph->numVertices);

    for (int i = 0; i < graph->numVertices; ++i) {
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    distance[startVertex] = 0;
    enqueue(queue, startVertex);

    printf("Caso de Teste #%d - BFS(%d)\n", testCase, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Iniciando busca em largura a partir de %d\n", currentVertex);

        Node* temp = graph->adjList[currentVertex];

        while (temp) {
            int neighbor = temp->vertex;

            if (distance[neighbor] == INT_MAX) {
                distance[neighbor] = distance[currentVertex] + 1;
                predecessor[neighbor] = currentVertex;
                enqueue(queue, neighbor);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < graph->numVertices; ++i) {
        printf("%d | ", i);
        if (distance[i] == INT_MAX) printf("- | -\n");
            
        else if(distance[i] == 0) printf("%d | -\n", distance[i]);

        else printf("%d | %d\n", distance[i], predecessor[i]);
    }

    if (distance[endVertex] == INT_MAX)
        printf("Sem caminho entre %d e %d\n", startVertex, endVertex);
    else {
        printf("Caminho entre %d e %d: %d", startVertex, endVertex, startVertex);
        int current = predecessor[endVertex];
        while (current != -1) {
            printf(" => %d", current);
            current = predecessor[current];
        }
        printf(" => %d\n", endVertex);
    }

    printf("--------\n");

    free(distance);
    free(predecessor);
    free(queue->items);
    free(queue);
}

int main() {
    int V, A, T;
    scanf("%d %d %d", &V, &A, &T);

    Graph* graph = createGraph(V);

    for (int i = 0; i < A; ++i) {
        int O, D;
        scanf("%d %d", &O, &D);
        addEdge(graph, O, D);
    }

    for (int i = 0; i < T; ++i) {
        int startVertex, endVertex;
        scanf("%d %d", &startVertex, &endVertex);
        bfs(graph, startVertex, endVertex, i + 1);
    }

    return 0;
}
