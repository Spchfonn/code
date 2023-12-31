#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

int find(bst_t *t,int v){
    if(t==NULL){
        return 0;
    }
    if(v==t->data){
        return 1;
    }
    if(v<t->data){
        return find(t->left,v);
    }
    if(v>t->data){
        return find(t->right,v);
    }
}

int find_min(bst_t *t){
    if(t->left==NULL){
        return t->data;
    }
    return find_min(t->left);
}

int find_max(bst_t *t){
    if(t->right==NULL){
        return t->data;
    }
    return find_max(t->right);
}

bst_t *insert(bst_t *t,int v){
    bst_t *newnode = (node_t *)malloc(sizeof (node_t));
    newnode->data = v;
    newnode->left = NULL;
    newnode->right = NULL;
    if(t==NULL){
        return newnode;
    }
    if(v<t->data){
        t->left = insert(t->left,v);
    }
    if(v>t->data){
        t->right = insert(t->right,v);
    }
    return t;
}

bst_t *delete(bst_t *t,int v){
    if(t==NULL){
        return t;
    }
    else if(v<t->data){
        t->left = delete(t->left,v);
    }
    else if(v>t->data){
        t->right = delete(t->right,v);
    }
    else if(t->data==v){
        if(t->left==NULL && t->right==NULL){
            free(t);
            t = NULL;
        }
        else if(t->left==NULL){
            bst_t *tmp = t;
            t = t->right;
            free(tmp);
        }
        else if(t->right==NULL){
            bst_t *tmp = t;
            t = t->left;
            free(tmp);
        }
        else{
            t->data = find_min(t->right);
            t->right = delete(t->right,find_min(t->right));
        }
    }
    return t;
}

int main(void)
{
    bst_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}