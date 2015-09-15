#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAXV 1000 /* maximum number of vertices */




typedef struct edgenode{
	int y;           /* adjacency info */
	int weight;      /* edge weight, if any */
	struct edgenode *next; /* next edge in list */
} edgenode; 


typedef struct graph{
	edgenode *edges[MAXV+1];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
	bool directed;
} graph;

void initialize_graph(graph *g, bool directed);
void read_graph(graph *g, bool directed);
void insert_edge(graph *g, int x, int y, bool directed);
void print_graph(graph *g);


void initialize_graph(graph *g, bool directed)
{
	int i;			/* counter */
	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;
	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
	for (i=1; i<=MAXV; i++) g->edges[i] = NULL;    //intialising edge pointer to NULL
}


void read_graph(graph *g, bool directed)
{
	int i;			/* counter */
	int m;			/* number of edges */
	int x, y;		/* vertices in edge (x,y) */
	initialize_graph(g, directed);
	scanf("%d %d",&(g->nvertices),&m);
	for (i=1; i<=m; i++) {
	scanf("%d %d",&x,&y);
	insert_edge(g,x,y,directed);
	}
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p;
	p = malloc(sizeof(edgenode));
	p->weight=0;
	p->y = y;
	p->next = g->edges[x];
	g->edges[x]=p;
	g->degree[x]++;
	if (directed == false)
		insert_edge(g,y,x,true);
	else
		g->nedges ++;
}

void print_graph(graph *g)
{
	int i;
	edgenode *p;
	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != NULL) {
			printf(" %d",p->y);
			p = p->next;
		}
		printf("\n");
	}
}

int main(void){
	graph g;
	initialize_graph( &g, false);
	read_graph( &g, false);
	print_graph(&g);
	
	return 0;


}
