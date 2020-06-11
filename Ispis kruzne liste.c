#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct Node {
    struct Node *next;
    int val;
} node;

/*
 * Ubacuje novi element s vrijednoscu val u kruznu listu iza elementa na poziciji pos.
 * Ako je pos jednak duljini ili visekratnik duljine liste head postaje novi element.
*/
int insert(node **head, int pos, int val) {
    node *new, *t;

    new = malloc(sizeof(node));
    if (new==NULL) return -1;
    new->val = val;
    new->next = NULL;

    if (*head==NULL) {
        *head = new;
        new->next = new;
        return 0;
    }
    for (t=*head; pos>1 && t->next!=NULL; pos--, t=t->next);
    if (t->next==*head) *head = new;
    new->next = t->next;
    t->next = new;
    return 0;
}

int print(node *head) {
    node *trenutni = head;

    if (!head) return -1; 

    printf("Lista: ");

    printf("%d ", trenutni->val);

    for (trenutni = head->next; trenutni != head; trenutni = trenutni->next){
        printf("%d\t", trenutni->val);
    }

    printf("\n");

    return 0;
}


int main() {
    node *head = NULL;
    char menu_choice;
    int pos, val, retval;

    do {
        //DEBUG("\n(d) dodaj - insert\n(i) ispis - print\n(e) Exit\n");

        scanf(" %c", &menu_choice);
        switch (menu_choice) {
            case 'd':
                //DEBUG("Pozicija: ");
                scanf("%d", &pos);
                //DEBUG("Vrijednost: ");
                scanf("%d", &val);
                retval = insert(&head, pos, val);
                if (retval==-1) printf("Alokacija nije uspjela.\n");
                break;
            case 'i':
                retval = print(head);
                if (retval==-1) printf("Lista je prazna.\n");
                break;
        }
    } while(menu_choice!='e');

    return 0;
}
