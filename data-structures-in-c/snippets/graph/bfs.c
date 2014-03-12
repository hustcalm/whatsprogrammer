#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define TRUE 1
#define FALSE 0

typedef struct queue *queue_pointer;
typedef struct queue {
	int vertex;
	queue_pointer link;
	}queue;

void addq(queue_pointer *, queue_pointer *, int);
int deleteq(queue_pointer *);

/**
 * breadth first traversal of a graph, starting with node v
 * the global array visited is initialized to 0, the queue
 * operations are similar to those described in Chapter 4
 */
void bfs(int v)
{
	node_pointer w;
	queue_pointer front, rear;
	front  = rear = NULL;	
	printf("%5d", v);
	visited[v] = TRUE;
	addq(&front, &rear, v);
	while(front){
		v = deleteq(&front);
		for(w = graph[v]; w; w = w->link)
			if(!visited[w->vertex]){
				printf("%5d",w->vertex);
				addq(&front, &rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
	}
}
