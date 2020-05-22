#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


// širina stupca
#define WIDTH 3
// jedinična visina stupca
#define HEIGHT 2
// razmak između stupaca
#define GAP 2

char **nacrtaj(int *p, int n, int h) {
  // alocirati memoriju za 2d polje koje treba vratiti
  // ucrtati ekvilajzer u polje

  char **polje;

  polje = malloc((h*HEIGHT)*sizeof(char *));
  for (int i = 0; i < h*HEIGHT; ++i){
    polje[i] = malloc((n*WIDTH + (n-1)*GAP)*sizeof(char));
    memset(polje[i], '.', (n*WIDTH + (n-1)*GAP)*sizeof(char));
  }

  for (int i = 0; i < n; ++i){
    for (int j = (h-p[i])*HEIGHT; j < h*HEIGHT; ++j) {
      for (int k = 0; k < WIDTH; ++k){
        polje[j][i*(WIDTH+GAP)+k] = '#';
      }
    }
  }

  return polje;
}

void ispisi(char **ans, int n, int h) {
  for (int i = 0; i < h*HEIGHT; ++i) {
    for (int j = 0; j < n*(WIDTH+GAP)-GAP; ++j) {
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }
}

int main() {

  int n, *p, h = 0;
  scanf("%d", &n);
  p = malloc(n*sizeof(int));

  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    h = p[i]>h ? p[i] : h;
  }

  char **ans = nacrtaj(p, n, h);
  ispisi(ans, n, h);

  // osloboditi cjelokupnu alociranu memoriju
  free(p);
  for (int i = 0; i < h*HEIGHT; ++i) {
    free(ans[i]);
  }
  free(ans);

  return 0;
}
