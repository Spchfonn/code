#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char data;
    struct node *next;
} node_t;
typedef node_t stack_t;

node_t *push(stack_t *s,char v){
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = v;
    node->next = s;
    s = node;
    return s;
}

char top(stack_t *s){
    char x=' ';
    if(s==NULL) return x;
    return s->data;
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

int check_par(int n){
    stack_t *s = NULL;
    char par[20][2] = {"(",")","{","}","[","]"};
    char p[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&p[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            if(p[i]==par[j][0]){
                if(j%2==0){
                    s=push(s,p[i]);
                    break;
                }
                else{
                    if(top(s)!=par[j-1][0] || s==NULL){
                        return 0;
                    }
                    else if(top(s)==par[j-1][0]){
                        s=pop(s);
                        break;
                    }
                }
            }
        }
    }
    if(s==NULL) return 1;
    else return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    if(n>0) printf("%d\n",check_par(n));
    return 0;
}