#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

float stringtofloat(char *s){
  float predznak = 1, decimale = -1, rez = 0;

  while(*s) {
    if (*s == '-'){
      predznak = -1;
    } else if (*s == '.'){ // nakon pojave decimalne točke postavi brojac na 0
      decimale = 0;
    } else if (isdigit(*s)){
      rez = rez*10 + (*s - '0'); //oduzima vrijednosti u asciiju i dobiva se broj
      if (decimale >= 0){
        decimale++;
      }
    }
    s++;
  }

  if (decimale <= 0){
    return predznak * rez;
  } else {
    return predznak * rez / pow(10, decimale);
  }
}


int main() {
  int n;
  char s[11];

  scanf ("%d", &n);

  for (int i = 0; i < n; ++i){
    scanf("%s", s);
    printf("%.3f\n", stringtofloat(s));
  }

  return 0;
}
