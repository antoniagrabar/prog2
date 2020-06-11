#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int zbroji_znamenke(int n) {
  if(n != 0){
    return n%10 + zbroji_znamenke(n/10);
  } else {
    return 0;
  }
}

int main() {
  int broj, zbroj;

  scanf("%d", &broj);
 
  zbroj = zbroji_znamenke(broj);

  printf("Zbroj znamenki broja %d je %d.", broj, zbroj);
  return 0;
}
