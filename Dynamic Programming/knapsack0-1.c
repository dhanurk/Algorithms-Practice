// knapsack problem using top down recursive programming approach.

#include <stdio.h>
#include <stdlib.h>

int knapsack(int capacity, int size, int *weight, int *value);
int max(int a, int b);

int main(){
  system("clear");
  int size;
  printf("Enter size of knapsack: ");
  scanf("%d", &size);
  int weight[size], value[size];
  for(int i = 0; i < size; i++) {
    printf("Enter value and weight for item %d respectively.\n", i + 1);
    scanf("%d%d", &value[i], &weight[i]);
  }
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
}

int max(int a, int b) {
  return a > b ? a : b;
}

int knapsack(int capacity, int size, int *weight, int *value) {
  if(size == 0 || weight == 0)
    return 0;
  if(capacity - weight[size - 1] < 0)
    return knapsack(capacity, size - 1, weight, value);
  return(max(knapsack(capacity, size - 1, weight, value), value[size - 1] + knapsack(capacity - weight[size - 1], size - 1, weight, value)));
}
