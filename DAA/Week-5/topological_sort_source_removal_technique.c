#include<stdio.h>

int number_of_vertices;

void topologicalSort(int adjacency_matrix[number_of_vertices][number_of_vertices], int indegree[number_of_vertices], int visited[number_of_vertices]) {
	for(int i=0; i<number_of_vertices; i++) {
		if(indegree[i]==0 && visited[i]==0) {
			printf("%c ", i+65);
			visited[i]=1;
			for(int j=0; j<number_of_vertices; j++)
				if(adjacency_matrix[i][j]) {
					adjacency_matrix[i][j]=0;
					indegree[j]--;
				}
			topologicalSort(adjacency_matrix, indegree, visited);
		}
	}
}

int main() {
	printf("Enter the number of vertices: ");
	scanf("%d", &number_of_vertices);
	int adjacency_matrix[number_of_vertices][number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		for(int j=0; j<number_of_vertices; j++)
			adjacency_matrix[i][j]=0;
	for(int i=0; i<number_of_vertices-1; i++) {
		for(int j=i+1; j<number_of_vertices; j++) {
			printf("Is %c connected to %c?: ", i+65, j+65);
			scanf("%d", &adjacency_matrix[i][j]);
		}
	}
	int indegree[number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		indegree[i]=0;
	for(int i=0; i<number_of_vertices; i++)
		for(int j=0; j<number_of_vertices; j++)
			if(adjacency_matrix[j][i]==1)
				indegree[i]++;
	int visited[number_of_vertices];
	for(int i=0; i<number_of_vertices; i++)
		visited[i]=0;
	printf("Topological Sort Using Source Removal Technique: ");
	topologicalSort(adjacency_matrix, indegree, visited);
	return 0;
}
