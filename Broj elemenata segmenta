#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int broj_elemenata(int a[][20], int *gl, int *dd) {

  int S = 20;

  int r1 = (gl-a[0])/S; //racuna opet indekse iz maina
  int s1 = (gl-a[0])%S;

  int r2 = (dd-a[0])/S; 
  int s2 = (dd-a[0])%S;

  return (r2-r1+1)*(s2-s1+1);

}

int main() {
  int q, i1, j1, i2, j2, a[10][20];
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
    printf("%d\n", broj_elemenata(a, &a[i1][j1], &a[i2][j2]));
  }
  return 0;
}
