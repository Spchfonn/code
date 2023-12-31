#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *l){
    int data;
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node_t *temp;
    temp=l;
    scanf(" %d",&data);
    node->data = data;
    node->next = NULL;
    if(l==NULL){
        return node;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=node;
    return l;
}

int get(node_t *l){
    int p;
    scanf(" %d",&p);
    node_t *temp;
    temp=l;
    while(p--){
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

int show(node_t *l){
    node_t *temp;
    temp=l;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

/*node_t *reverse(node_t *l){
    node_t *temp,*temp2,*head;
    temp2=NULL;
    head=l;
    while(temp2!=head){
        temp=l;
        while(temp->next!=temp2){
            temp=temp->next;
        }
        temp2=temp;
        printf("%d ",temp2->data);
    }
    printf("\n");
}*/

node_t *reverse(node_t *l){
    node_t *temp=l,*pre=NULL,*pos;
    while(temp!=NULL){
        pos=temp->next;
        temp->next=pre;
        pre=temp;
        temp=pos;
    }
    l=pre;
    return l;
}

node_t *cut(node_t *l){
    node_t *temp,*head,*tail;
    head=tail=l;
    temp=l;
    int m,n;
    scanf(" %d %d",&m,&n);
    int x=n-m;
    while(m--){
        head=head->next;
    }
    l=head;
    tail=head;
    while(x--){
        tail=tail->next;
    }
    tail->next=NULL;
    return l;
}

int main(void) {
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}