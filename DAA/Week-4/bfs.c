#include<stdio.h>

int number_of_vertices;
int queue[100];
int front = -1;
int rear = -1;

void bfsAtVertex(int vertex, int adjacency_matrix[number_of_vertices][number_of_vertices], int visited[number_of_vertices]) {
	printf("%c ", vertex+65);
	visited[vertex]=1;
	for(int i=0; i<number_of_vertices; i++)
		if(i!=vertex && !visited[i] && adjacency_matrix[vertex][i]==1)
			queue[++rear] = i;
}

void bfs(int adjacency_matrix[number_of_vertices][number_of_vertices], int *visited) {
	int num;
	queue[++rear]=0;
	while(front!=rear) {
		num = queue[++front];
		if(!visited[num])
			bfsAtVertex(num, adjacency_matrix, visited);
	}
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

	bfs(adjacency_matrix, visited);
	return 0;
}
