#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int key;
    struct _node *next;
} Node;

typedef struct _graph {
    int vertices;
    Node **adjList;
} Graph;

typedef struct _queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

// Funções relacionadas à fila
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Funções relacionadas ao grafo
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = dest;
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


// Função BFS
void BFS(Graph* graph, int startVertex, int endVertex, int* dist, int* pred) {
    Queue* queue = createQueue(graph->vertices);

    // Inicialização dos arrays dist e pred
    for (int i = 0; i < graph->vertices; ++i) {
        dist[i] = -1;
        pred[i] = -1;
    }
    
    // Inicialização para o vértice de origem
    dist[startVertex] = 0;
    pred[startVertex] = -1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);

        //definitivamente o print nao e aqui
        printf("Iniciando busca em larguara a partir de %d\n", currentVertex);
        Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->key;

            if (dist[adjVertex] == -1) {
                dist[adjVertex] = dist[currentVertex] + 1;
                pred[adjVertex] = currentVertex;
                enqueue(queue, adjVertex);
            }
            //printf("Iniciando busca em larguara a partir de %d\n", adjVertex);
            temp = temp->next;
        }
    }

    // Libera a memória usada pela fila
    free(queue->array);
    free(queue);
}

// Função para imprimir o caminho entre a origem e o destino
void printPath(int* pred, int startVertex, int endVertex) {
    if (endVertex == -1 || startVertex == endVertex)
        printf("%d", startVertex);
    else {
        printPath(pred, startVertex, pred[endVertex]);
        printf(" => %d", endVertex);
    }
}

// Função principal
int main() {
    int V, A, T;
    scanf("%d %d %d", &V, &A, &T);

    Graph* graph = createGraph(V);

    // Leitura das arestas
    for (int i = 0; i < A; ++i) {
        int O, D;
        scanf("%d %d", &O, &D);
        addEdge(graph, O, D);
    }

    // Processamento dos casos de teste
    for (int t = 1; t <= T; ++t) {
        int origem, destino;
        scanf("%d %d", &origem, &destino);

        int* dist = (int*)malloc(V * sizeof(int));
        int* pred = (int*)malloc(V * sizeof(int));

        // Executa a busca em largura (BFS)
        BFS(graph, origem, destino, dist, pred);

        // Imprime os resultados
        printf("Caso de Teste #%d - BFS(%d)\n", t, origem);

        for (int i = 0; i < V; ++i) {
            printf("%d | ", i);
            if (dist[i] == -1) 
            {
                printf("- | -\n");
            }

            else if(dist[i] == 0)
            {
                printf("%d | -\n", dist[i]);
            }
            
            else printf("%d | %d\n", dist[i], pred[i]);
        }

        // Verifica se há caminho entre origem e destino
        if (dist[destino] == -1) printf("Sem caminho entre %d e %d\n", origem, destino);
        else 
        {
            printf("Caminho entre %d e %d: ", origem, destino);
            printPath(pred, origem, destino);
            printf("\n");
        }

        // Libera a memória usada pelos arrays dist e pred
        free(dist);
        free(pred);

        // Adiciona uma quebra de linha entre os casos de teste
        printf("\n");
    }

    // Libera a memória usada pelo grafo
    for (int i = 0; i < V; ++i) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}
