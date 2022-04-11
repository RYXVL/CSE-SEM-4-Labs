#include<stdio.h>
#include<stdlib.h>

int number_of_vertices;
int pushStack[100];
int tos_pushStack = -1;
int popStack[100];
int tos_popStack = -1;

void dfsAtVertex(int vertex, int adjacency_matrix[number_of_vertices][number_of_vertices], int visited[number_of_vertices]) {
	printf("%c ", vertex+65);
	pushStack[++tos_pushStack] = vertex;
	visited[vertex]=1;
	int flag = 0;
	for(int i=0; i<number_of_vertices; i++) {
		if(i!=vertex && !(visited[i]) && adjacency_matrix[vertex][i]==1)
			dfsAtVertex(i, adjacency_matrix, visited);
	}
	popStack[++tos_popStack] = vertex;
}

void dfs(int adjacency_matrix[number_of_vertices][number_of_vertices], int *visited) {
	for(int i=0; i<number_of_vertices; i++)
		if(!visited[i])
			dfsAtVertex(i, adjacency_matrix, visited);
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &number_of_vertices);
	int adjacency_matrix[number_of_vertices][number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		for(int j=0; j<number_of_vertices; j++)
			adjacency_matrix[i][j]=0;
	int visited[number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		visited[i]=0;
	for(int i=0; i<number_of_vertices-1; i++) {
		for(int j=i+1; j<number_of_vertices; j++) {
			printf("Is %c connected to %c?: ", i+65, j+65);
			scanf("%d", &adjacency_matrix[i][j]);
			adjacency_matrix[j][i]=adjacency_matrix[i][j];
		}
	}
	printf("DFS Traveral: ");
	dfs(adjacency_matrix, visited);
	printf("\nPush Order: ");
	for(int i=0; i<=tos_pushStack; i++)
		printf("%c ", pushStack[i]+65);
	printf("\nPop Order: ");
	for(int i=0; i<=tos_popStack; i++)
		printf("%c ", popStack[i]+65);
	return 0;
}
