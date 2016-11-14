// Warhall's algorithm --> to find transitive closure of a given directed graph.
// Central point of algorithm is that we can comppute all the elements of each matrix R(k) from its immediate predecessor R(k-1).
// Complexity O(n^3)

#include <stdio.h>
#include <stdlib.h>

int getTransClos(int **transClos, int vertex);

int main() {
  system("clear");
  int vertex;
  printf("Enter number of vertices: ");
  scanf(" %d", &vertex);
  int **adjMat, **transClos; // graph's adjacency matrix and transitive closure matrices respectively
  adjMat = (int **) malloc(vertex * sizeof(int **));
  transClos = (int **) malloc(vertex * sizeof(int **));
  for(int i = 0; i < vertex; i++){
    adjMat[i] = (int *) malloc(vertex * sizeof(int *));
    transClos[i] = (int *) malloc(vertex * sizeof(int *));
  }
  printf("Enter adjacency matrix for the graph.\n");
  for(int i = 0; i < vertex; i++)
    for(int j = 0; j < vertex; j++) {
      scanf(" %d", &adjMat[i][j]);
      transClos[i][j] = adjMat[i][j]; // transClos(0) = adjMat
    }
  getTransClos(transClos, vertex);
  printf("\nTransitive closure for the given graph is: \n");
  for(int i = 0; i < vertex; i++) {
    for(int j = 0; j < vertex; j++)
      printf("%d ", transClos[i][j]);
    printf("\n");
  }
  printf("\nPress enter to continue.\n");
  char b;
  scanf("%c", &b);
  scanf("%c", &b);
  system("clear");
}

int getTransClos(int **transClos, int vertex) {
  for(int k = 0; k < vertex; k++)
    for(int i = 0; i < vertex; i++)
      for(int j = 0; j < vertex; j++)
	transClos[i][j] = transClos[i][j] | (transClos[i][k] & transClos[k][j]); // Rij(k) = Rij(k - 1) | (Rik[k - 1] & Rkj[k - 1]) --> relation between R(k) and R(k -1)
  return 1;
}
