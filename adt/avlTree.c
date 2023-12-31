#include <stdio.h>
#include <stdlib.h>
#include <week9.h>
#ifndef __avl_tree__
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t avl_t;
#endif

avl_t *rot_left(avl_t *t){
    avl_t *tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    t->height -= 2;
    return tmp;
}

avl_t *rot_right(avl_t *t){
    avl_t *tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    t->height -= 2;
    return tmp;
}

avl_t *rot_left_right(avl_t *t){
    t->left = rot_left(t->left);
    t = rot_right(t);
    return t;
}

avl_t *rot_right_left(avl_t *t){
    t->right = rot_right(t->right);
    t = rot_left(t);
    return t;
}

avl_t *insert(avl_t *t,int v){
    int l_height,r_height;
    if(t==NULL){
        t = (avl_t*)malloc(sizeof(avl_t));
        t->data = v;
        t->height = 0;
        t->left = NULL;
        t->right = NULL;
    }
    else if(v<t->data){
        t->left = insert(t->left,v);
        if(t->left==NULL) l_height = -1;
        else l_height = t->left->height;
        if(t->right==NULL) r_height = -1;
        else r_height = t->right->height;
        t->height = (l_height>r_height ? l_height : r_height) + 1;
        if(l_height-r_height==2){
            if(v<t->left->data){
                t = rot_right(t);
            }
            else{
                t = rot_left_right(t);
            }
        }
    }
    else if(v>t->data){
        t->right = insert(t->right,v);
        if(t->left==NULL) l_height = -1;
        else l_height = t->left->height;
        if(t->right==NULL) r_height = -1;
        else r_height = t->right->height;
        t->height = (l_height>r_height ? l_height : r_height) + 1;
        if(r_height-l_height==2){
            if(v>t->right->data){
                t = rot_left(t);
            }
            else{
                t = rot_right_left(t);
            }
        }
    }
    if(t->left==NULL) l_height=-1;
    else l_height = t->left->height;
    if(t->right==NULL) r_height=-1;
    else r_height = t->right->height;
    t->height = (l_height>r_height ? l_height : r_height) + 1;
    return t;
}

avl_t *delete(avl_t *t,int v){
    int l_height,r_height,ll_height,lr_height,rl_height,rr_height;
    if(t==NULL){
        return t;
    }
    else if(v<t->data){
        t->left = delete(t->left,v);
        if(t->left == NULL) l_height = -1;
        else l_height = t->left->height;
        if(t->right == NULL) r_height = -1;
        else r_height = t->right->height;
        t->height = (l_height > r_height ? l_height : r_height) + 1;
        if(r_height-l_height == 2){
            if(t->right->left == NULL) rl_height = -1;
            else rl_height = t->right->left->height;
            if(t->right->right == NULL) rr_height = -1;
            else rr_height = t->right->right->height;
            if(rl_height > rr_height){
                t = rot_right_left(t);
            }
            else{
                t = rot_left(t);
            }
        }
    }
    else if(v>t->data){
        t->right = delete(t->right,v);
        if(t->left == NULL) l_height = -1;
        else l_height = t->left->height;
        if(t->right == NULL) r_height = -1;
        else r_height = t->right->height;
        t->height = (l_height > r_height ? l_height : r_height) + 1;
        if(l_height-r_height == 2){
            if(t->left->left == NULL) ll_height = -1;
            else ll_height = t->left->left->height;
            if(t->left->right == NULL) lr_height = -1;
            else lr_height = t->left->right->height;
            if(lr_height > ll_height){
                t = rot_left_right(t);
            }
            else{
                t = rot_right(t);
            }
        }
    }
    else{
        if(t->left==NULL && t->right==NULL){
            free(t);
            t = NULL;
            return t;
        }
        else if(t->left==NULL){
            avl_t *tmp = t;
            t = t->right;
            free(tmp);
        }
        else if(t->right==NULL){
            avl_t *tmp = t;
            t = t->left;
            free(tmp);
        }
        else{
            avl_t *tmp = t->right;
            while(tmp->left!=NULL){
                tmp = tmp->left;
            }
            t->data = tmp->data;
            t->right = delete(t->right,tmp->data);
            if(t->left == NULL) l_height = -1;
            else l_height = t->left->height;
            if(t->right == NULL) r_height = -1;
            else r_height = t->right->height;
            t->height = (l_height > r_height ? l_height : r_height) + 1;
            if(l_height-r_height == 2){
                if(t->left->left == NULL) ll_height = -1;
                else ll_height = t->left->left->height;
                if(t->left->right == NULL) lr_height = -1;
                else lr_height = t->left->right->height;
                if(lr_height > ll_height){
                    t = rot_left_right(t);
                }
                else{
                    t = rot_right(t);
                }
            }
        }
    }
    if(t->left==NULL) l_height = -1;
    else l_height = t->left->height;
    if(t->right==NULL) r_height = -1;
    else r_height = t->right->height;
    t->height = (l_height > r_height ? l_height : r_height) + 1;
    return t;
}

int main(void)
{
    avl_t *t = NULL;
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
            t = delete(t, data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}