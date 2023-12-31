#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    float data;
    struct node *next;
} node_t;
typedef node_t stack_t;

node_t *push(stack_t *s,float v){
    node_t *node = (node_t *)malloc(sizeof (node_t));
    node->data = v;
    node->next = s;
    s = node;
    return s;
}

float top(stack_t *s){
    if(s==NULL) return 0;
    else return s->data;
}

node_t *pop(stack_t *s){
    node_t *tmp = s;
    s=s->next;
    free(tmp);
    return s;
}

int main(void) {
    stack_t *s = NULL;
    int n;
    float ans=0.0;
    scanf("%d", &n);
    char data[n];
    for(int i=0;i<n;i++){
        scanf(" %c",&data[i]);
    }
    for(int i=0;i<n;i++){
        if(data[i]>=48 && data[i]<=57){
            float v = (float)data[i]-'0';
            s = push(s,v);        
        }
        else{
            if(data[i]=='+'){
                float res1 = top(s);
                s = pop(s);
                float res2 = top(s);
                s = pop(s);
                ans = res2+res1;
                s = push(s,ans);
            }
            else if(data[i]=='-'){
                float res1 = top(s);
                s = pop(s);
                float res2 = top(s);
                s = pop(s);
                ans = res2-res1;
                s = push(s,ans);
            }
            else if(data[i]=='*'){
                float res1 = top(s);
                s = pop(s);
                float res2 = top(s);
                s = pop(s);
                ans = res2*res1;
                s = push(s,ans);
            }
            else if(data[i]=='/'){
                float res1 = top(s);
                s = pop(s);
                float res2 = top(s);
                s = pop(s);
                ans = res2/res1;
                s = push(s,ans);
            }
        }
    }
    printf("%.2f\n",ans);
    return 0;
}