#define MAX_VERTICES 50 /*maximum number of vertices*/
typedef struct node *node_pointer;
typedef struct node {
	int vertex;
	struct node *link;
	}node;

node_pointer graph[MAX_VERTICES];
int n = 0;
short int visited[MAX_VERTICES];
