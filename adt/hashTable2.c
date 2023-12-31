#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char *item_t;

typedef struct hash{
    item_t *table;
    int size;
    int hash_key;
} hash_t;

hash_t *init_hashtable(int m, int hash_key){
    hash_t *hash = (hash_t*)malloc(sizeof(hash_t));
    hash->table = (item_t*)malloc(sizeof(item_t)*m);
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
    int index = hash_func(text,h->size,h->hash_key);
    item_t new = (item_t)malloc(sizeof(char)*TEXTSIZE);
    strcpy(new,text);
    int i=0;
    while(1){
        int k = (i+i*i)/2;
        if(h->table[(index+k)%h->size]==NULL){
            h->table[(index+k)%h->size] = new;
            break;
        }
        i++;
    }
}

int search(hash_t *h,char *text){
    int index = hash_func(text,h->size,h->hash_key);
    int i=0;
    while(1){
        int k = (i+i*i)/2;
        if(h->table[(index+k)%h->size]==NULL) return -1;
        if(strcmp(h->table[(index+k)%h->size],text)==0) return (index+k)%h->size;
        i++;
    }
}

int main(void){
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char)*TEXTSIZE);
    for(i = 0; i < n; i++){
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