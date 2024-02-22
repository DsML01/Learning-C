#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int key;
    struct _node *next;
} node;

typedef struct _graph
{
    node **adjlist;
    int vertices;
} graph;

typedef struct _queue
{
    int *items;
    int front;
    int rear;
} queue;

node *createnode(int key)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

graph *creategraph(int vertices)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->vertices = vertices;
    g->adjlist = (node **)malloc(vertices * sizeof(node *));
    for (int i = 0; i < vertices; ++i)
        g->adjlist[i] = NULL;
    return g;
}

queue *createqueue(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->items = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isempty(queue *q)
{
    return q->front == -1;
}

void enqueue(queue *q, int value)
{
    if (q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->items[q->rear] = value;
    }
    else
    {
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q)
{
    int value;
    if (isempty(q))
    {
        return -1;
    }
    else
    {
        value = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return value;
    }
}

void add_edge(graph *g, int origem, int destino)
{
    node *newnode = createnode(destino);
    newnode->next = g->adjlist[origem];
    g->adjlist[origem] = newnode;

    newnode = createnode(origem);
    newnode->next = g->adjlist[destino];
    g->adjlist[destino] = newnode;
}

void bfs(graph *g, int origem, int destino)
{
    int *visited = (int *)malloc(g->vertices * sizeof(int));
    for (int i = 0; i < g->vertices; i++)
        visited[i] = 0;

    queue *q = createqueue(g->vertices);
    visited[origem] = 1;
    enqueue(q, origem);

    printf("Iniciando busca em largura a partir de %d\n", origem);

    while (!isempty(q))
    {
        int current = dequeue(q);
        printf("Visitando vértice %d\n", current);

        node *temp = g->adjlist[current];
        while (temp)
        {
            int adj = temp->key;
            if (!visited[adj])
            {
                visited[adj] = 1;
                enqueue(q, adj);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

int main()
{
    int vertices, arestas, casos;
    scanf("%d %d %d", &vertices, &arestas, &casos);

    graph *g = creategraph(vertices);

    for (int i = 0; i < arestas; ++i)
    {
        int origem, destino;
        scanf("%d %d", &origem, &destino);
        add_edge(g, origem, destino);
    }

    for (int i = 0; i < casos; ++i)
    {
        int origem, destino;
        scanf("%d %d", &origem, &destino);

        printf("Caso de Teste #%d - BFS(%d)\n", i + 1, origem);
        bfs(g, origem, destino);
        printf("Sem caminho entre %d e %d\n", origem, destino);
    }

    free(g);
    return 0;
}
