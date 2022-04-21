#include<stdio.h>

int number_of_vertices;
int popStack[100];
int tos_popStack = -1;

void dfsAtVertex(int vertex, int adjacency_matrix[number_of_vertices][number_of_vertices], int visited[number_of_vertices]) {
	visited[vertex]=1;
	for(int i=0; i<number_of_vertices; i++) {
		if(i!=vertex && !(visited[i]) && adjacency_matrix[vertex][i]==1)
			dfsAtVertex(i, adjacency_matrix, visited);
	}
	popStack[++tos_popStack] = vertex;
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
	dfsAtVertex(0, adjacency_matrix, visited);
	printf("\nTopological Sort Using DFS: ");
	for(int i=tos_popStack; i>=0; i--)
		printf("%c ", popStack[i]+65);
	return 0;
}
