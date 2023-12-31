#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int num;
    int limit;
    struct node *next;
}node_t;

node_t *create(node_t *l,int n){
    node_t *temp;
    temp=NULL;
    for(int i=1;i<=n;i++){
        node_t *node = (node_t *)malloc(sizeof (node_t));
        node->num=i;
        scanf("%d",&node->limit);
        node->next=NULL;
        if(l==NULL){
            l=node;
            temp=node;
        }
        else{
            temp->next=node;
            temp=node;
        }
    }
    if(temp!=NULL){
        temp->next=l;
    }
    return l;
}

int show(node_t *l){
    node_t *temp;
    temp=l;
    printf("%d %d\n",temp->num,temp->limit);
    temp=temp->next;
    while(temp!=l){
        printf("%d %d\n",temp->num,temp->limit);
        temp=temp->next;
    }
}

int find(int k,int no){
    while(no>0){
        if(k==(no%10)) return 1;
        no/=10;
    }
    if(k==no) return 1;
    else return 0;
}

int play(node_t *l,int k){
    node_t *temp,*pre=NULL;
    temp=l;
    int cnt=1;
    while(temp->next!=NULL){
        if(cnt%k==0 || find(k,cnt)){
            temp->limit--;
            if(temp->limit<0){
                node_t *del=NULL;
                if(pre->next->next==pre){
                    del=temp;
                    temp=pre;
                    temp->next=NULL;
                    pre=NULL;
                    free(del);
                }
                else{
                    del=temp;
                    temp=temp->next;
                    pre->next=pre->next->next;
                    free(del);
                }
            }
            else{
                pre=temp;
                temp=temp->next;
            }
        }
        else{
            pre=temp;
            temp=temp->next;
        }
        cnt++;
    }
    return temp->num;
}

int main(){
    int n,k;
    node_t *mynode;
    mynode=NULL;
    scanf("%d %d",&n,&k);
    mynode=create(mynode,n);
    printf("%d",play(mynode,k));

    return 0;
}