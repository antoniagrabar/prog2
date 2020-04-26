#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int *naj(int *a, int *b, int *c){
  if (*a > *b && *a > *c){
    return a;
  } else if (*b > *a && *b > *c){
    return b;
  } else return c;
}

int main() {
  int a, b, c, *pnaj = NULL;

  scanf ("%d %d %d", &a, &b, &c);

  pnaj = naj(&a, &b, &c);
  printf("%d\n%d\n", *pnaj, a+b+c-*pnaj);
}
