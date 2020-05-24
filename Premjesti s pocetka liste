#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_STRING 100

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

typedef struct Node {
    char val;
    struct Node *next;
} node;

node *create_list(char *list_string) {
    node *trenutni=NULL, *novi=NULL, *head;
    int i;

    for(i=0; i<strlen(list_string); i++) {
        novi = (node *)malloc(sizeof(node));
        novi->val = list_string[i];
        novi->next = NULL;
        if (!trenutni) head = novi;
        else trenutni->next = novi;
        trenutni = novi;
    }
    return head;
}

int print_list(node *head) {
    node *trenutni;

    if(!head) return -1; //ako je prazna lista
    for(trenutni=head; trenutni!=NULL; trenutni=trenutni->next){
        printf("%c ", trenutni->val);
    }
    printf("\n");
    return 0;
}

void premjesti_s_pocetka(node **head, int k) {
    int i = 1;
    node *old_head = *head, *new_head = NULL, *new_tail = NULL, *trenutni = NULL;

    if (*head == NULL || k <= 0){
        return;
    } 
    
    for(trenutni = *head; trenutni->next != NULL; trenutni = trenutni->next, ++i){
        if (i == k){
            new_head = trenutni->next;
            new_tail = trenutni;
        }
    }

    if (i > k){
        *head = new_head;
        trenutni->next = old_head;
        new_tail->next = NULL;
    }
}


/*void premjesti_s_pocetka(node **head, int k) {
    node *trenutni, *kti = NULL;
    trenutni = *head;
    --k;

    if (k < 0){
        return;
    }

    while(trenutni != NULL && k > 0){
        trenutni = trenutni->next;
        --k;
    }

    if (trenutni && trenutni->next){
        kti = trenutni;

        while(trenutni->next != NULL){
            trenutni = trenutni->next;
        }

        trenutni->next = *head;
        *head = kti->next;
        kti->next = NULL;
    }
}
*/

int main () {
    node *head=NULL;
    int menu_choice, k;
    char c, list_string[MAX_TREE_STRING];

    setbuf(stdout, NULL);

    do {
        menu_choice = 0;
        //DEBUG("\n1 Kreiraj listu");
        //DEBUG("\n2 Ispis");
        //DEBUG("\n3 Premjesti s pocetka");
        //DEBUG("\n4 Izlaz\n");
        scanf("%d", &menu_choice);
        switch (menu_choice) {
            case 1:
                //DEBUG("Unesite listu kao niz alfanumerickih znakova bez razmaka: ");
                scanf(" %s", list_string);
                head = create_list(list_string);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                scanf("%d", &k);
                premjesti_s_pocetka(&head, k);
                break;
            case 4:
                break;
            default:
                while((c=getchar())!='\n' && c!=EOF);
        }
    } while(menu_choice!=4);
    return 0;
}
