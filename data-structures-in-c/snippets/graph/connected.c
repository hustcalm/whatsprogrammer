void connected(void)
{
	int i;
	for (i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i);
			printf("\n");
		}
	}
}
