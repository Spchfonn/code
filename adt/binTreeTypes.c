#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif

int is_full(tree_t *t){
    if(t==NULL){
        return 0;
    }
    if(t->left==NULL && t->right==NULL){
        return 1;
    } 
    if(t->left==NULL || t->right==NULL){
        return 0;
    }
    return is_full(t->left)*is_full(t->right);
}

int size(tree_t *t){
    if(t==NULL){
        return 0;
    }
    return size(t->left) + size(t->right) + 1;
}

int height(tree_t *t){
    if(t==NULL){
        return -1;
    }
    int hl = height(t->left);
    int hr = height(t->right);
    return (hl>hr)? hl+1 : hr+1;
}

int is_perfect(tree_t *t){
    if(t==NULL){
        return 0;
    }
    if(size(t)==(int)pow(2.0,height(t)+1)-1){
        return 1;
    }
    return 0;
}

int is_complete(tree_t *t){
    if(t==NULL){
        return 1;
    }
    if(height(t)==0 || is_perfect(t)){
        return 1;
    }
    if((is_perfect(t->left) && height(t->left)==height(t)-1) && is_complete(t->right)){
        return 1;
    }
    if((is_perfect(t->right) && height(t->right)==height(t)-2) && is_complete(t->left)){
        return 1;
    }
    return 0;
}

int is_degenerate(tree_t *t){
    if(t==NULL){
        return 0;
    }
    if(t->left!=NULL && t->right!=NULL){
        return 0;
    }
    if(t->left!=NULL){
        is_degenerate(t->left);
    }
    if(t->right!=NULL){
        is_degenerate(t->right);
    }
    return 1;
}

int is_skewed(tree_t *t){
    if(!is_degenerate(t)){
        return 0;
    }
    int h = height(t)-1;
    if(t->left!=NULL){
        tree_t *tmp = t->left;
        while(h--){
            if(tmp==NULL) return 0;
            tmp = tmp->left;
        }
    }
    if(t->right!=NULL){
        tree_t *tmp = t->right;
        while(h--){
            if(tmp==NULL) return 0;
            tmp = tmp->right;
        }
    }
    return 1;
}

int main(void)
{
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t),is_perfect(t), is_complete(t),is_degenerate(t), is_skewed(t));
    return 0;
}