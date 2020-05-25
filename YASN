#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct Node {
  int friend;
  struct Node *next;
} node;

void insert(node **p, int v) {
  node *novi = malloc(sizeof(node));
  novi->friend = v;
  novi->next = *p;
  *p = novi;
}

int are_friends(node **g, int p, int r) {
  for (node *cur = *(g+p); cur != NULL; cur = cur->next) {
    if (cur->friend == r) return 1;
  }
  return 0;
}

int main() {
  int n, m, q; 
  //n - broj korisnika društvene mreže
  //m - broj prijateljskih veza
  //q - broj upita

  node **g;
  scanf("%d %d", &n, &m);
  g = malloc((n+1) * sizeof(node *)); //polje dvostrukih pointera

  for (int i = 0; i <= n; ++i){
    g[i] = NULL;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    // U listu prijatelja od u ubaciti v
    insert(g+u, v);
    // U listu prijatelja od v ubaciti u
    insert(g+v, u);
  }

  scanf("%d", &q);

  for (int i = 0; i < q; ++i){
    int p, r;
    scanf("%d %d", &p, &r);
    if (are_friends(g, p, r)) printf("DA\n");
    else printf("NE\n");
  }

  return 0;
}
