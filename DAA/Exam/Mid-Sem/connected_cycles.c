#include<stdio.h>

int nov;
int cycles = 0;

void dfs(int adj[][nov], int visited[], int node, int *cond) {
	visited[node] = 1;
	for(int i=0; i<nov; i++) {
		if(i!=node && adj[node][i] && visited[i]) {
			*cond = 1;
			cycles++;
		}
		if(i!=node && adj[node][i] && !visited[i])
			dfs(adj, visited, i, cond);
	}
}

int main() {
	int cond = 0;
	printf("Enter the number of  vertices: ");
	scanf("%d", &nov);
	int adj[nov][nov];
	for(int i=0; i<nov; i++)
		for(int j=0; j<nov; j++)
			adj[i][j] = 0;
	for(int i=0; i<nov; i++) {
		for(int j=0; j<nov; j++) {
			if(i==j) continue;
			printf("Is %d connected to %d?: ", i, j);
			scanf("%d", &adj[i][j]);
		}
	}
	int visited[nov];
	for(int i=0; i<nov; i++)
		visited[i] = 0;
	dfs(adj, visited, 0, &cond);
	if(cond)
		printf("The Graph is Connected.\n");
	else
		printf("The Graph is not Connected.\n");
	printf("Number of cycles: %d", cycles);
	return 0;
}
