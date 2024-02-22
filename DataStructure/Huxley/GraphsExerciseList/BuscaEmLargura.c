#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int item;
    struct _node *next;

} node;

typedef struct _graph
{
    //vertices eh um array para ponteiros
    //distance vai ser um array  
    node **adjlist;
    int *distance;
    int *predecessor;
    int vertices_amount;

} graph;

typedef struct _queue
{
    int *itens;
    int front;
    int rear;
    int size;
    int capacity;
} queue;

queue *createqueue(int n)
{
    queue *new_queue = (queue*) calloc(1, sizeof(queue));

    new_queue->itens = (int*) calloc(n , sizeof(int));
    new_queue->front = 0;
    new_queue->rear = 0;
    new_queue->size = 0;
    new_queue->capacity = n;

    return new_queue;
}

node *createnode(int item)
{
    node *new_node = (node*) calloc(1,sizeof(node));

    new_node->item = item;
    new_node->next = NULL;

    return new_node;
}

graph *create_graph(int n)
{
    graph *new_graph = (graph*) calloc(1 , sizeof(graph));

    new_graph->adjlist = (node **) calloc(n , sizeof(node *));

    new_graph->distance = (int *) calloc(n , sizeof(int));

    new_graph->predecessor = (int *) calloc(n, sizeof(int));

    new_graph->vertices_amount = n;

    for(int i = 0; i < n; i++)
    {
        new_graph->adjlist[i] = NULL;
        new_graph->distance[i] = 0; //initialize all the vertices as non-visited
        new_graph->predecessor[i] = 0; //initialize all the vertices without predecessors
    }

    return new_graph;
}

int isfull(queue *fila)
{
    return fila->capacity == fila->size;
}

int isempty(queue *fila)
{
    return  fila->size == 0;
}

void enqueue(queue *fila, int item)
{
    fila->itens[fila->rear] = item;
    fila->rear++;
    fila->size++;
}

int deque(queue *fila)
{
    int item = fila->itens[fila->front];
    fila->front = (fila->front + 1) % fila->capacity;
    fila->size--;

    return item;    
}

//caso ocorra algum erro, verificar se a origem e o destino estao dentro do meu range
void add_edge(graph *graph, int origem, int destino)
{
    node *new_node = createnode(destino);
    new_node->item = destino;
    new_node->next = NULL;

    if(graph->adjlist[origem] == NULL || destino <= graph->adjlist[origem]->item)
    {
        new_node->next = graph->adjlist[origem];

        graph->adjlist[origem] = new_node;

        return;
    }

    node *previous = NULL;
    node *current = graph->adjlist[origem];

    while(current && destino > current->item)
    {
        previous = current;
        current = current->next;
    }

    new_node->next = current;
    previous->next = new_node;

    return;
}

void bfs(graph *grafo, int origem, int destino)
{
    int n = grafo->vertices_amount;

    queue *fila = createqueue(n);

    for(int i = 0; i < n; i++)
    {
        grafo->distance[i] = -1;
        grafo->predecessor[i] = -1;
    }

    grafo->distance[origem] = 0;

    enqueue(fila, origem);

    while(!isempty(fila))
    {
        int currentvertex = deque(fila);

        printf("Iniciando busca em largura a partir de %d\n", currentvertex);

        node *aux = grafo->adjlist[currentvertex];


        while(aux != NULL)
        {
            int adjVertex = aux->item;

            if(grafo->distance[adjVertex] == -1)
            {
                grafo->distance[adjVertex] = grafo->distance[currentvertex] + 1;  
                grafo->predecessor[adjVertex] = currentvertex;
                enqueue(fila, adjVertex);
            }

            aux = aux->next;
        }
    }
    puts("");
    //libera a fila
    free(fila->itens);
    free(fila);
}

void printpath(int predecessor[], int origem, int destino)
{
    if(origem == destino) printf("%d", origem);

    else
    {
        printpath(predecessor, origem, predecessor[destino]);
        printf(" => %d", destino);
    }

    return;
}

int main()
{
    //v = quantidade de vertices do grafo
    //a = quantidade de arestas presentes no grafo
    //t = quantidade de casos a serem examinados
    int v, a, t;

    scanf("%d %d %d", &v, &a, &t);

    graph *graph = create_graph(v);

    for(int i = 1; i <= a; i++)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);

        add_edge(graph, vertex1, vertex2);
    }

    //quantidade de casos teste
    for(int i = 1; i <= t; i++)
    {
        //aqui, testaremos se ha caminho possivel do vertice 1 ao vertice 2
        int origem, destino;
        scanf("%d %d", &origem, &destino);

        puts("");
        puts("--------");
        puts("");
        printf("Caso de Teste #%d - BFS(%d)\n",i ,origem);
        puts("");

        bfs(graph, origem, destino);

        //IMPRIME OS RESULTADOS
        for(int i = 0; i < v; i++)
        {
            if(graph->distance[i] == -1) printf("%d | - | -\n", i);

            else if(graph->distance[i] == 0) printf("%d | %d | -\n", i, graph->distance[i]);

            else printf("%d | %d | %d\n", i, graph->distance[i], graph->predecessor[i]);
        }

        if(graph->distance[destino] == -1) printf("\nSem caminho entre %d e %d\n", origem, destino);

        else
        {
            puts("");
            printf("Caminho entre %d e %d: ", origem, destino);
            printpath(graph->predecessor, origem, destino);
            puts("");
        }
    }
    
    puts("\n--------");

    return 0;
}