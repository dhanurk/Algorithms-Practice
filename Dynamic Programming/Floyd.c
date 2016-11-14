// Floyd's algorithm --> to find distance of a given directed weight graph. (All Pair Shortest Problem).
// Central point of algorithm is that we can comppute all the elements of each matrix R(k) from its immediate predecessor R(k-1).
// Complexity O(n^3)

#include <stdio.h>
#include <stdlib.h>

int getDistMat(int **distMat, int vertex);
int min(int a, int b);

int main() {
  system("clear");
  int vertex;
  printf("Enter number of vertices: ");
  scanf(" %d", &vertex);
  int **adjMat, **distMat; // graph's adjacency matrix and transitive closure matrices respectively
  adjMat = (int **) malloc(vertex * sizeof(int **));
  distMat = (int **) malloc(vertex * sizeof(int **));
  for(int i = 0; i < vertex; i++){
    adjMat[i] = (int *) malloc(vertex * sizeof(int *));
    distMat[i] = (int *) malloc(vertex * sizeof(int *));
  }
  printf("Enter adjacency matrix for the graph.\n");
  for(int i = 0; i < vertex; i++)
    for(int j = 0; j < vertex; j++) {
      scanf(" %d", &adjMat[i][j]);
      distMat[i][j] = adjMat[i][j]; // transClos(0) = adjMat
    }
  getDistMat(distMat, vertex);
  printf("\nDistance matrix for the given graph is: \n");
  for(int i = 0; i < vertex; i++) {
    for(int j = 0; j < vertex; j++)
      printf("%d ", distMat[i][j]);
    printf("\n");
  }
  printf("\nPress enter to continue.\n");
  char b;
  scanf("%c", &b);
  scanf("%c", &b);
  system("clear");
}

int getDistMat(int **distMat, int vertex) {
  for(int k = 0; k < vertex; k++)
    for(int i = 0; i < vertex; i++)
      for(int j = 0; j < vertex; j++)
	distMat[i][j] = min(distMat[i][j] , (distMat[i][k] + distMat[k][j])); // Rij(k) = Rij(k - 1) | (Rik[k - 1] & Rkj[k - 1]) --> relation between R(k) and R(k -1)
  return 1;
}
int min(int a, int b) {
  return a < b ? a : b;
}
