#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAXN 1000

//           0  45  90  135 180 225 270 315
int dr[8] = {0, -1, -1, -1,  0,  1,  1,  1};
int ds[8] = {1,  1,  0, -1, -1, -1,  0,  1};

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, r[MAXN], s[MAXN], a[MAXN], l[MAXN];
  char c[MAXN];
  int mnr = 1e9, mxr = -1e9, h;
  int mns = 1e9, mxs = -1e9, w;

  // deklarirati varijablu za dinamički alocirano 2d polje
  char **polje;

  scanf("%d", &n);

  for (int k = 0; k < n; ++k) {
    scanf("%d%d%d%d %c", &r[k], &s[k], &a[k], &l[k], &c[k]);
    mnr = min(mnr, min(r[k], r[k] + dr[a[k]/45]*l[k]));
    mxr = max(mxr, max(r[k], r[k] + dr[a[k]/45]*l[k]));
    mns = min(mns, min(s[k], s[k] + ds[a[k]/45]*l[k]));
    mxs = max(mxs, max(s[k], s[k] + ds[a[k]/45]*l[k]));
  }

  h = mxr-mnr;
  w = mxs-mns;

  // alocirati polje dovoljnih dimenzija (h * w) i unositi tragove
  polje = malloc(h * sizeof(char *));

  for (int i = 0; i < h; ++i){
    polje[i] = malloc(w * sizeof(char));
    memset(polje[i], '.', w * sizeof(char));
  }

  for (int k = 0; k < n; ++k){
    int i = r[k] - mnr; //jednu od zraka ce postavit na [0,0]
    int j = s[k] - mns;

    for (int p = 0; p < l[k]; ++p){
      polje[i][j] = c[k];
      i += dr[a[k]/45]; //dijelimo kut s 45 da dobijemo indeks polja dr
      j += ds[a[k]/45];
    }
  }

  // ispisati polje
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < w; ++j){
      printf("%c", polje[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < h; ++i){
    free(polje[i]);
  }

  free(polje);

  return 0;
}
