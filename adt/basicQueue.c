#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;
typedef node_t queue_t;

queue_t *rear;

queue_t *enqueue(queue_t *q,int v){
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = v;
    node->next = NULL;
    if(q==NULL){
        q=node;
        rear=q;
    }
    else{
        rear->next=node;
        rear=rear->next;
    }
    return q;
}

queue_t *dequeue(queue_t *q){
    if(q==NULL){
        printf("Queue is empty.\n");
    }
    else{
        node_t *tmp=q;
        q=q->next;
        //rear=q;
        printf("%d\n",tmp->data);
        free(tmp);
    }
    return q;
}

void show(queue_t *q){
    if(q==NULL) printf("Queue is empty.");
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}

void empty(queue_t *q){
    if(q==NULL) printf("Queue is empty.\n");
    else printf("Queue is not empty.\n");
}

int size(queue_t *q){
    int cnt=0;
    while(q!=NULL){
        cnt++;
        q=q->next;
    }
    printf("%d\n",cnt);
}

int main(void) {
    queue_t *q = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch(command) {
            case 1:
                scanf("%d", &value);
                q = enqueue(q, value);
                break;
            case 2:
                q = dequeue(q);
                break;
            case 3:
                show(q);
                break;
            case 4:
                empty(q);
                break;
            case 5:
                size(q);
                break;
        }
    }
    return 0;
}