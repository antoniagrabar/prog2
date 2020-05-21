#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...)printf(__VA_ARGS__)
#endif

int main() {
  int n;
  int max_redak = 1, max_stupac = 1;
  char **matrica;

  matrica = malloc(max_redak * sizeof(char *));

  for (int i = 0; i < max_redak; ++i){
    matrica[i] = malloc(max_stupac * sizeof(char));
    memset(matrica[i], ' ', max_stupac * sizeof(char)); //memset(void *str, int c, size_t n)
  }

  scanf("%d", &n);

  for (int q = 0; q < n; ++q){
    int r, s;
    char c;

    scanf(" %d %d %c", &r, &s, &c);

    r++;
    s++; //povecavamo jer unosimo indekse

    //realociranje ako je uneseni redak veći od maksimalnog
    if (r > max_redak){
      matrica = realloc(matrica, r * sizeof(char *));

      for (int i = max_redak; i < r; ++i){
        matrica[i] = malloc(max_stupac * sizeof(char));
        memset(matrica[i], ' ', max_stupac * sizeof(char));
      }

      max_redak = r;
    }

    //realociranje ako je uneseni stupac veći od maksimalnog
    if(s > max_stupac){
      
        for (int i = 0; i < max_redak; ++i){
          matrica[i] = realloc(matrica[i], s * sizeof(char));
          memset(matrica[i] + max_stupac, ' ', (s - max_stupac) * sizeof(char));
        }

        max_stupac = s;
    }

    matrica[--r][--s] = c; //vracamo na indeks koji je upisan
  }

  for (int i = 0; i < max_redak; ++i){
    for (int j = 0; j < max_stupac; ++j){
      printf("%c", matrica[i][j]);
    }
    printf("\n");
  }


  return 0;
}
