#define FALSE 0
#define TRUE 1
short int visited[MAX_VERTICES];

/**
 * depth first search of a graph beginning with vertex v.
 */
void dfs(int v)
{
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link;)
		if(!visited[w->vertex])
			dfs(w-vertex);
}

