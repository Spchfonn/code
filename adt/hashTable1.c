#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21
typedef struct item{
    char *text;
    struct item *next;
} item_t;
typedef struct hash{
    item_t **table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key){
    hash_t *hash = (hash_t*)malloc(sizeof(hash_t));
    hash->table = (item_t**)malloc(sizeof(item_t*)*m);
    hash->size = m;
    hash->hash_key = hash_key;
    for(int i=0;i<m;i++){
        hash->table[i] = NULL;
    }
    return hash;
}

unsigned int f(char *text,int n,int key){
    if(n==0) return text[0];
    return key*f(text,n-1,key)+text[n];
}

int hash_func(char *text,int m,int hash_key){
    return f(text,strlen(text)-1,hash_key)%m;
}

void insert(hash_t *h,char *text){
    item_t *new = (item_t*)malloc(sizeof(item_t));
    int index = hash_func(text,h->size,h->hash_key);
    new->text = (char*)malloc(sizeof(char)*TEXTSIZE);
    strcpy(new->text,text);
    new->next = h->table[index];
    h->table[index] = new;
}

int search(hash_t *h,char *text){
    int index = hash_func(text,h->size,h->hash_key);
    item_t *tmp = h->table[index];
    while(tmp!=NULL){
        if(strcmp(tmp->text,text)==0) return index;
        tmp = tmp->next;
    }
    return -1;
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char) * TEXTSIZE);
    for (i = 0; i < n; i++){
        scanf("%d %s", &command, text);
        switch (command){
        case 1:
            insert(hashtable, text);
            break;
        case 2:
            printf("%d\n",search(hashtable, text));
            break;
        }
    }
    return 0;
}