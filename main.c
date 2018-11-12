#include <stdio.h>
#include <stdlib.h>

struct node{
    char cha;
    struct node *next;
};

void create(struct node **, int a);
void display(struct node *);
char survivor(struct node **, int k);

int main(){
    struct node *head = NULL;
    char survive;
    int skip, person;

    printf("Person Number: ");
    scanf("%d", &person);
    create(&head, person);
    printf("The persons in circular list are:\n");
    display(head);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);
    survive = survivor(&head, skip);
    printf("The person to survive is : %c\n", survive);
    free(head);

    return 0;
}

char survivor(struct node **head, int k){
    struct node *p, *q;
    int i;

    q = p = *head;
    while (p->next != p){
        for (i = 0; i < k - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%c has been killed.\n", p->cha);
        free(p);
        p = q->next;
    }

    *head = p;
    return (p->cha);
}

void create (struct node **head, int a){
    struct node *temp, *rear;
    char ch = 'A';
    do{
        temp = (struct node *)malloc(sizeof(struct node));
        temp->cha = ch;
        temp->next = NULL;
        if(*head == NULL){
            *head = temp;
        }

        else{
            rear->next = temp;
        }

        rear = temp;
        ch++;
        a--;
    } while (a != 0);
    rear->next = *head;
}

void display(struct node *head) {
    struct node *temp;
    temp = head;
    printf("%3c", temp->cha);
    temp = temp->next;
    while (head != temp){
        printf("%3c", temp->cha);
        temp = temp->next;
    }

    printf("\n");

}
