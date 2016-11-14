// knapsack problem using bottom up dynamic programming approach.

#include <stdio.h>
#include <stdlib.h>

int knapsack(int capacity, int size, int *weight, int *value);
int max(int a, int b);
int knapCap[100][100];
int main(){
  //system("clear");
  int size;
  printf("Enter size of knapsack: ");
  scanf("%d", &size);
  int weight[size], value[size];
  int capacity;
  printf("Enter knapsack capacity: ");
  scanf("%d", &capacity);
  for(int i = 0; i < size; i++) {
    printf("Enter value and weight for item %d respectively.\n", i + 1);
    scanf("%d%d", &value[i], &weight[i]);
  }
  int ans = 0;
  ans = knapsack(capacity, size, weight, value);
  printf("Maximum value of knapsack for the given capacity is: %d\n", ans);
  printf("Press enter to exit.\n");
  char b;
  scanf("%c", &b);
  scanf("%c", &b);
}

int max(int a, int b) {
  return a > b ? a : b;
}

int knapsack(int capacity, int size, int *weight, int *value) {
  int knapCap[size + 1][capacity + 1];
  for(int i = 0; i <= size; i++) {
    for(int w = 0; w <= capacity; w++) {
      if(i == 0 || w == 0)
	knapCap[i][w] = 0;
      else if(weight[i - 1] <= w)
	knapCap[i][w] = max(knapCap[i - 1][w], value[i - 1] + knapCap[i - 1][w - weight[i - 1]]);
      else
	knapCap[i][w] = knapCap[i - 1][w];
    }
  }
  return knapCap[size][capacity];
}
