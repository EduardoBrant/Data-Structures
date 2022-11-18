#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node* createNode(int);

struct graph
{
    int numVertices;
    struct node** adjacentLists;
};

struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v ;
    newNode->next = NULL;
    return newNode;
}

struct graph* createAGraph(int vertices)
{
    struct graph *graph = malloc(sizeof(struct graph));
    graph->numVertices = vertices;
    graph->adjacentLists = malloc(vertices*sizeof(struct node*));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjacentLists[i] = NULL;        
    }

    return graph;
}

void addEdge(struct graph *graph, int a, int b)
{
    struct node *newNode = createNode(b);
    newNode->next = graph->adjacentLists[a];
    graph->adjacentLists[a] = newNode;

    newNode = createNode(a);
    newNode->next = graph->adjacentLists[b];
    graph->adjacentLists[b] = newNode;
}

void printGraph(struct graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct node *temp = graph->adjacentLists[i];
        printf("\nVertex %d\n: ",i);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

int main()
{
    struct graph *graph = createAGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    printGraph(graph);

    return 0;
}

