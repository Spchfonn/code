#include <stdio.h>
#include <stdlib.h>
typedef struct heap{
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m){
    heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
    heap->data = (int*)malloc(sizeof(int)*m);
    heap->last_index = 0;
    return heap;
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

heap_t *insert(heap_t *h,int v){
    h->last_index++;
    h->data[h->last_index] = v;
    int i = h->last_index;
    while(i>1){
        int parent = i/2;
        if(h->data[i] > h->data[parent]){
            swap(&h->data[i],&h->data[parent]);
            i = parent;
        }
        else break;
    }
}

heap_t *delete_max(heap_t *h){
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int i = 1;
    while(i*2<h->last_index){
        if(h->data[i] < h->data[i*2]){
            swap(&h->data[i],&h->data[i*2]);
            i*=2;
        }
        else if(h->data[i] < h->data[i*2+1]){
            swap(&h->data[i],&h->data[i*2+1]);
            i = i*2+1;
        }
        else break;
    }
}

int find_max(heap_t *h){
    if(h->last_index<1){
        return -1;
    }
    return h->data[1];
}

heap_t *update_key(heap_t *h,int old,int new){
    int i = 1;
    while(i<=h->last_index){
        if(h->data[i]==old){
            h->data[i] = new;
            break;
        }
        i++;
    }
    if(old<new){
        while(i>1){
            if(h->data[i] > h->data[i/2]){
                swap(&h->data[i],&h->data[i/2]);
                i/=2;
            }
            else break;
        }
    }
    else if(old>new){
        while(i*2<h->last_index){
            if(h->data[i] < h->data[i*2]){
                swap(&h->data[i],&h->data[i*2]);
                i*=2;
            }
            else if(h->data[i] < h->data[i*2+1]){
                swap(&h->data[i],&h->data[i*2+1]);
                i = i*2+1;
            }
            else break;
        }
    }
}

void bfs(heap_t *h){
    int i = 1;
    while(i<=h->last_index){
        printf("%d ",h->data[i]);
        i++;
    }
    printf("\n");
}

int main(void){
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i = 0; i < n; i++){
        scanf("%d", &command);
        switch (command){
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key,new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}