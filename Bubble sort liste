#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif


typedef struct Node{
  struct Node *next;
  int val;
} node;

int add_node(node **head, int val) {
  node *new;

  new = (node *)malloc(sizeof(node));
  if (!new) return -1;

  new->val = val;
  new->next = *head;
  *head = new;

  return 0;
}

void print_list(node *head) {
  node *trenutni;

  if(!head) return;

  for(trenutni=head; trenutni!=NULL; trenutni=trenutni->next) printf("%d  ", trenutni->val);
  printf("\n");
}

void bubble_sort(node **head) {
  node *t1, *t2, *t3;
  int nSwaps;
    
  // sortiranje ima smisla samo ako su barem dva elementa u listi
  if (!*head || !(*head)->next) return;

  do{

    nSwaps = 0; //broj zamjena
    t1 = *head;
    t2 = t1->next;

    //provjeravanje prva 2 elemena u listi
    if (t1->val > t2->val){
      t1->next = t2->next;
      t2->next = t1;
      *head = t2;
      nSwaps++;
    }

     // iteracija po ostatku liste sa t1, t2 i t3
    for (t1 = *head; t1->next->next != NULL; t1 = t1->next){
      t2 = t1->next;
      t3 = t2->next;

      //t1 je vec sortiran pa uspoređujemo samo t2 i t3
      if (t2->val > t3->val){
        t1->next = t3;
        t2->next = t3->next;
        t3->next = t2;
        nSwaps++;
      }
    }

    print_list(*head);

  } while (nSwaps);
}



int main() {
  int n;
  node *head = NULL;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int val;
    scanf("%d", &val);
    add_node(&head, val);
  }

  printf("Lista prije sortiranja:\n");
  print_list(head);

  printf("\nLista za vrijeme sortiranja:\n");
  bubble_sort(&head);

  printf("\nSortirana lista:\n");
  print_list(head);

  return 0;
}
