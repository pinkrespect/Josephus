#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;

int main(void) {
    struct node *temp, *x;
    int count, person, mth;

    printf("How many people are there?: ");
    scanf("%d", &person);

    printf("What number did you choose?: ");
    scanf("%d", &mth);

    for(count = 0; count < person; count++) {
        temp = malloc(sizeof(struct node));
        temp->data = count;
        temp->link = NULL;

        if(start == NULL) {
            start = temp;
        }
        else {
            x = start;
            while(x->link != NULL) {
                x = x->link;
            }
            x->link = temp;
            printf("%3d ", x->data);
        }
    }
   // TODO: 여기에 요세푸스 함수 넣을 것.
    x = start;

    while(x != NULL) { // 요세푸스 출력구
        printf("%3d ", x->data);
        x = x->link;
    }
    printf("\n");
    return 0;
}

