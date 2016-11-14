// knapsack problem using memory function approach.

#include <stdio.h>
#include <stdlib.h>

int knapsack(int capacity, int size, int *weight, int *value);
int max(int a, int b);
int v[100][100];
int main(){
  system("clear");
  int size;
  printf("Enter size of knapsack: ");
  scanf("%d", &size);
  int weight[size + 1], value[size + 1];
  for(int i = 1; i <= size; i++) {
    printf("Enter value and weight for item %d respectively.\n", i);
    scanf("%d%d", &value[i], &weight[i]);
  }
  for(int i = 1; i < 100; i++)
    for(int j = 1; j < 100; j++)
      v[i][j] = -1;
  int capacity;
  printf("Enter knapsack capacity: ");
  scanf("%d", &capacity);
  int ans = 0;
  ans = knapsack(capacity, size, weight, value);
  printf("Maximum value of knapsack for the given capacity is: %d\n", ans);
  printf("Press enter to exit.\n");
  char b;
  scanf("%c", &b);
  scanf("%c", &b);
  system("clear");
}

int max(int a, int b) {
  return a > b ? a : b;
}

int knapsack(int capacity, int size, int *weight, int *value) {
  int values;
  if(v[size][capacity] < 0) {
    if(capacity - weight[size] < 0)
      values = knapsack(capacity, size - 1, weight, value);
    else
      values = (max(knapsack(capacity, size - 1, weight, value), value[size] + knapsack(capacity - weight[size], size - 1, weight, value)));
    v[size][capacity] = values;
  }
  return v[size][capacity];
}
