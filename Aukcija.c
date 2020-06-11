#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct {
  char ime[32];
  int pocetna_cijena;
  int postignuta_cijena;
}artikl;


void fix(char name[]){
  name[0] = toupper(name[0]);
  for (int i = 1; i < strlen(name); ++i){
    name[i] = tolower(name[i]);
  }
  name[strlen(name)] = '\0';
}

void check_price(artikl p[], int br_art, int c, char ime[]) {
  for (int i = 0; i < br_art; i++) {
    if (!strcmp(p[i].ime, ime) && c >= p[i].pocetna_cijena && c >= p[i].postignuta_cijena) {
      p[i].postignuta_cijena = c;
    }
  }
}

int compare(artikl p1, artikl p2) {
  if (p1.postignuta_cijena == p2. postignuta_cijena) {
    return strcmp(p1.ime, p2.ime);
  }
  return p1.postignuta_cijena > p2.postignuta_cijena ? 0 : 1;
}

void selection_sort(artikl p[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (compare(p[max], p[j]) > 0) {
        max = j;
      }
    }
    artikl tmp = p[max];
    p[max] = p[i];
    p[i] = tmp;
  }
}



int main() {

  artikl a[100];
  int n, size = 0, c;
  char ime[32];
  int zarada = 0;

  scanf("%s", a[size].ime);

  while(a[size].ime[0] != '-') {
    scanf("%d", &a[size].pocetna_cijena);
    fix(a[size].ime);
    a[size].postignuta_cijena = 0;
    size++;
    scanf("%s", a[size].ime);
  }

  FILE *fp;
  fp = fopen("input.dat", "r");


  while(fscanf(fp, " %s %d", ime, &n) > 0) {
    for (int i = 0; i < n; i++) {
      fscanf(fp, "%s %d", ime, &c);
      fix(ime);
      check_price(a, size, c, ime);
    }
  }

  fclose(fp);

  selection_sort(a, size);

  for (int i = 0; i < size; ++i){
    zarada += a[i].postignuta_cijena;
  }

  fp = fopen("output.dat", "w");

  printf("%d\n", zarada);
  fprintf(fp, "%d\n", zarada);

  for (int i = 0; i < size; ++i){
    if (a[i].postignuta_cijena){
      printf("%s %d\n", a[i].ime, a[i].postignuta_cijena);
      fprintf(fp, "%s %d\n", a[i].ime, a[i].postignuta_cijena);
    }
  }

  fclose(fp);

  return 0;
}
