#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char data;
    struct node *next;
} node_t;
typedef node_t stack_t;

node_t *push(stack_t *s,int v){
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = v;
    node->next = s;
    s = node;
    return s;
}

char top(stack_t *s){
    if(s==NULL) return 0;
    else return s->data;
}

node_t *pop(stack_t *s){
    if(s==NULL) {}
    else{
        node_t *tmp = s;
        s=s->next;
        free(tmp);
        return s;
    }
}

int check_pass(stack_t *s,char p){
    s = push(s,p);
    while(p!='x'){
        scanf(" %c",&p);
        if(p!='x') s = push(s,p);
    }
    while(p!='y'){
        scanf(" %c",&p);
        if(p!='y'){
            if(p!=top(s)){
                return 0;
            }
            s = pop(s);
        }
    }
    if(s!=NULL) return 0;
    return 1;
}

int main(void) {
    stack_t *s = NULL;
    char p;
    scanf(" %c",&p);
    printf("%d\n",check_pass(s,p));
    return 0;
}