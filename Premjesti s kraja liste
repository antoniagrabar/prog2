#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define MAX_TREE_STRING 100

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

    if(!head) return -1;
    for(trenutni=head; trenutni!=NULL; trenutni=trenutni->next)
        printf("%c ", trenutni->val);
    printf("\n");
    return 0;
}

void premjesti_s_kraja(node **head, int k) {
    node *t1 = NULL, *t2 = NULL, *old_head = *head;
    int n = 1;
    
    if (*head==NULL || k<=0) return;

    for(t1=*head; t1->next != NULL; t1=t1->next) n++;

    t2 = *head;

    if (n > k)
    {
        for (int i = 0; i < n - k - 1; ++i){
            t2 = t2->next;
        }

        *head = t2->next;
        t2->next = NULL;
        t1->next = old_head;
    }
}

int main () {
    node *head=NULL;
    int menu_choice, k;
    char c, list_string[MAX_TREE_STRING];

    setbuf(stdout, NULL);
    do {
        menu_choice = 0;
        //DEBUG("\n1 Kreiraj listu \n2 Ispis");
        //DEBUG("\n3 Premjesti s kraja");
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
                premjesti_s_kraja(&head, k);
                break;
            case 4:
                break;
            default:
                while((c=getchar())!='\n' && c!=EOF);
        }
    } while(menu_choice!=4);
    return 0;
}
