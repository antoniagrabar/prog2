#include <stdio.h>

#ifndef DEBUG
#define DEBUG(...)printf(_VA_ARGS_)
#endif

#define MAXA 200

int main() {

  int n;
  int br; // broj mladih
  int mn; // godine starosti najmladje osobe
  int *pbr=NULL, *pmn=NULL;
  pbr = &br; //pbr pokazuje na lokaciju na kojoj je zapisana vrijednost br
  pmn = &mn;
  *pbr = 0; //0 je vrijednost zapisana na lokaciji na koju pokazuje pbr
  *pmn = MAXA;

  scanf("%d", &n);

  for (int i=0; i<n; ++i) {
    int a;
    scanf("%d", &a);
    if (10 <= a && a <= 30) {
        *pbr += 1; // moze i ++*pbr ili (*pbr)++ ali ne i *pbr++
    }
    if (a < *pmn) *pmn = a;
  }

  printf("%d\n", *pbr);
  printf("%d\n", *pmn);

  return 0;
}
