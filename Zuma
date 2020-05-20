#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

int main() {

  int l, n;
  char *s;

  scanf("%d", &l);

  s = malloc((l+1) * sizeof(char));
  scanf("%s", s);
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    char b;
    int p;
    scanf(" %c%d", &b, &p);
  
    ++l;
    s = realloc(s, l * sizeof(char));

    // shift za jedno mjesto u desno pocevsi od znaka na indeksu p-1
    for (int j = l-1; j >= p-1; --j) {
      s[j+1] = s[j];
    }

    s[p-1] = b; //niz sa ubacenom kuglicom

    int le = p-1; //indeks kuglice koju smo dodali
    while(le>0 && s[le-1]==b) { //broji na kojem indeksu je najlijevija ista kuglica
      --le;
    }

    int ri = p-1;
    while(ri<l-1 && s[ri+1]==b) { //indeks najdesnije iste kuglice
      ++ri;
    }
    
    int d = ri-le+1; //koliko je istih kuglica zaredom

    if (d>=3) {

      // shift u lijevo za duljinu d pocevsi od ri+1
      for (int j = ri+1; j <= l; ++j) { //pomice se toliko puta koliko je preostalih kuglica
        s[j-d] = s[j];
      }
      l -= d;
      s = realloc(s, l * sizeof(char));
    }
    printf("%s\n", s);
  }

  return 0;
}
