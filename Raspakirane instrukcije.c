#include <stdio.h>
#include <stdlib.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


void unpack_instructions(char *a, int n, char **u, int *nu) {
  // odrediti veličinu raspakiranog niza nu
  *nu = 0;
  for (int i = 0; i < n; i=i+2){
    *nu += *(a + i) - '0';
  }
  
  // alocirati memorijski prostor dovoljan za raspakirane instrukcije
  *u = malloc((*nu) * sizeof(char));

  // upisati raspakirane instrukcije
  int k = 0;
  for (int i = 0; i < n; i+=2){
    for (int j = 0; j < a[i] - '0'; ++j){
      *(*u+k) = a[i+1];
      k++;
    }
  }
}

void print(char *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%c", a[i]);
  }
  printf("\n");
}

int main() {
  int n, nu;
  char *a, *u;

  // učitati duljinu niza n
  scanf("%d", &n);

  // alocirati prostor za unos instrukcija
  a = malloc((n+1) * sizeof(char));

  // učitati niz instrukcija
  scanf("%s", a);

  unpack_instructions(a, n, &u, &nu);
  print(u, nu);
  return 0;
}
