#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

void ispis(char **ans, int h, int w) {
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      printf("%c", ans[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n, h, w;
  char u[1000];

  scanf("%d%d%d", &h, &w, &n);
  scanf(" %s", u);

  // deklarirati varijablu ans za dinamički alocirano 2d polje
  char **ans;

  // alocirati polje dovoljnih dimenzija (h * w) i unijeti uzorak
  ans = malloc(h * sizeof(char *));

  for (int i = 0; i < h; ++i){
    ans[i] = malloc(w * sizeof(char));
  }

  int k = 0;
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      ans[i][j] = u[k];
      k++;

      if (k == n){
        k = 0;
      }
    }
  }

  // ispisati polje
  ispis(ans, h, w);
  return 0;
}
