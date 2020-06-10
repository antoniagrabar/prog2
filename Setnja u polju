#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

char *pomakni(char a[][20], char *cur, char d) {

  int R = 10;
  int S = 20;
  int r = (cur-a[0])/S; //racuna opet indekse iz maina
  int s = (cur-a[0])%S;

  
    if (d == 'U' && r != 0){
      cur -= S;
    } else if (d == 'D' && r != R-1){
      cur += S;
    } else if (d == 'L' && s != 0){
      cur -= 1;
    } else if (d == 'R' && s != S-1) {
      cur += 1;
    }

  return cur;
}

int main() {
  int q;
  char a[10][20], *cur;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 20; ++j) {
      scanf(" %c", &a[i][j]);
    }
  }
  cur = &a[0][0];

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    char d;
    scanf(" %c", &d);
    cur = pomakni(a, cur, d);
    printf("%c", *cur);
  }
  printf("\n");
  return 0;
}
