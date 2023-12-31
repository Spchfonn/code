#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[20];
    int freq;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;

tree_t *create(char *w,int freq){
    tree_t *new = (tree_t*)malloc(sizeof(tree_t));
    strcpy(new->word,w);
    new->freq = freq;
    new->left = NULL;
    new->right = NULL;
    return new;
}

tree_t *merge(tree_t *t1,tree_t *t2){
    tree_t *new = (tree_t*)malloc(sizeof(tree_t));
    new->freq = t1->freq + t2->freq;
    new->left = t1;
    new->right = t2;
    return new;
}

typedef struct heap{
    tree_t **data;
    int last_index;
} heap_t;

heap_t *init_heap(int n){
    n++;
    heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
    heap->data = (tree_t**)malloc(sizeof(tree_t*)*n);
    heap->last_index = 0;
    return heap;
}

void swap(tree_t **a,tree_t **b){
    tree_t *tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert(heap_t *h,tree_t *t){
    h->last_index++;
    h->data[h->last_index] = t;
    int i = h->last_index;
    while(i>1){
        if(h->data[i]->freq < h->data[i/2]->freq){
            swap(&h->data[i],&h->data[i/2]);
            i/=2;
        }
        else break;
    }
}

tree_t *delete_min(heap_t *h){
    tree_t *delete_tree = h->data[1];
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int i = 1;
    while(i*2<=h->last_index){
        if(h->data[i]->freq > h->data[i*2]->freq || h->data[i]->freq > h->data[i*2+1]->freq){
            if(h->data[i*2]->freq <= h->data[i*2+1]->freq){
                swap(&h->data[i],&h->data[i*2]);
                i*=2;
            }
            else{
                swap(&h->data[i],&h->data[i*2+1]);
                i = i*2+1;
            }
        }
        else break;
    }
    return delete_tree;
}

heap_t *huffcode(heap_t *h){
    while(h->last_index > 1){
        tree_t *t1 = delete_min(h);
        tree_t *t2 = delete_min(h);
        tree_t *tree = merge(t1,t2);
        insert(h,tree);
    }
    return h;
}

char code[100];
void print_dfs(tree_t *t,int cnt){
    if(t->left==NULL && t->right==NULL){
        printf("%s: ",t->word);
        for(int i=0;i<cnt;i++) printf("%c",code[i]);
        printf("\n");
    }
    else{
        code[cnt] = '0';
        print_dfs(t->left,cnt+1);
        code[cnt] = '1';
        print_dfs(t->right,cnt+1);
    }
}

int main(void){
    heap_t *min_heap = NULL;
    int n,freq;
    char w[20];
    scanf("%d",&n);
    min_heap = init_heap(n);
    while(n--){
        scanf(" %s %d",w,&freq);
        tree_t *tree = create(w,freq);
        insert(min_heap,tree);
    }
    min_heap = huffcode(min_heap);
    print_dfs(min_heap->data[1],0);
    
    return 0;
}

/*
6
i 3
am 3
ok 1
a 1
boy 1
how 1
*/