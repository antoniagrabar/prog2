#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void rotiraj(int *a, int size, int **prvi) {

  *prvi += 1;

  if ((*prvi - a) >= size){
    *prvi = a;
  }
}

void ispisi(int *a, int size, int *prvi) {

  for (int i = (prvi - a); i < size; ++i){
    printf("%d ", *(a+i));
  }

  for (int i = 0; i < (prvi - a); ++i){
    printf("%d ", *(a+i));
  }
}

int main() {

  int n, k, *a, *prvi;
  scanf("%d%d", &n, &k);
  a = malloc(n * sizeof(int));
  prvi = a;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < k; ++i) {
    rotiraj(a, n, &prvi);
  }
  ispisi(a, n, prvi);
  free(a);
  return 0;
}
