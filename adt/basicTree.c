#include <stdio.h>
#include <stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}stack_t;

stack_t *push(stack_t *s,int v){
    stack_t *node = (stack_t *)malloc(sizeof (stack_t));
    node->data = v;
    node->next = s;
    s = node;
    return s;
}

typedef struct node{
    int value,depth;
    struct node *first_child,*next_sibling,*last_child,*parent,*prev_sibling;
}node_t;

typedef node_t tree_t;

node_t *createnode(int value){
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->value = value;
    newnode->first_child=newnode->next_sibling=newnode->last_child=newnode->parent=newnode->prev_sibling=NULL;
    return newnode;
}

tree_t *searchPos(tree_t *t,int value){
    if(t==NULL || t->value==value) return t;
    tree_t *pos = searchPos(t->first_child,value);
    if(pos != NULL) return pos;
    else{
        return searchPos(t->next_sibling,value);
    } 
}

tree_t *attach(tree_t *t,int parent,int child){
    node_t *newnode = createnode(child);
    if(t==NULL){
        newnode->depth = 0;
        return newnode;
    }
    node_t *pos = searchPos(t,parent);
    newnode->depth = pos->depth+1;
    newnode->parent = pos;
    if(pos->first_child==NULL){
        pos->first_child = pos->last_child = newnode;
    }
    else{
        newnode->prev_sibling = pos->last_child;
        pos->last_child->next_sibling = newnode;
        pos->last_child = newnode;
    }
    return t;
}

tree_t *detach(tree_t *t,int value){
    if(t->value==value){
        if(t->prev_sibling!=NULL){
            t->prev_sibling->next_sibling = t->next_sibling;
        }
        else{
            t->parent->first_child = t->next_sibling;
        }
        if(t->next_sibling!=NULL){
            t->next_sibling->prev_sibling = t->prev_sibling;
        }
        else{
            t->parent->last_child = t->prev_sibling;
        }
        return t;
    }
    if(t->next_sibling!=NULL){
        detach(t->next_sibling,value);
    }
    if(t->first_child!=NULL){
        detach(t->first_child,value);
    }
    return t;
}

int search(tree_t *t,int value){
    if(searchPos(t,value)!=NULL) return 1;
    else return 0;
}

int degree(tree_t *t,int value){
    int cnt=0;
    node_t *pos = searchPos(t,value);
    if(t==NULL) return 0;
    if(pos->first_child!=NULL){
        node_t *temp = pos->first_child;
        while(temp!=NULL){
            cnt++;
            temp = temp->next_sibling;
        }
    }
    return cnt;
}

int is_root(tree_t *t,int value){
    node_t *pos = searchPos(t,value);
    if(pos==NULL) return 0;
    if(pos->depth==0) return 1;
    return 0;
}

int is_leaf(tree_t *t,int value){
    node_t *pos = searchPos(t,value);
    if(pos==NULL) return 0;
    if(pos->first_child==NULL) return 1;
    return 0;
}

void siblings(tree_t *t,int value){
    node_t *pos = searchPos(t,value);
    if(pos->parent!=NULL){
        node_t *temp = pos->parent->first_child;
        while(temp!=NULL){
            if(temp!=pos){
                printf("%d ",temp->value);
            }
            temp = temp->next_sibling;
        }
    }
    printf("\n");
}

int depth(tree_t *t,int value){
    node_t *pos = searchPos(t,value);
    return pos->depth;
}

void print_path(tree_t *t,int start,int finish){
    stack_t *s = NULL;
    node_t *pos_start = searchPos(t,start);
    node_t *pos_finish = searchPos(t,finish);
    node_t *temp = pos_finish;
    while(temp->value!=pos_start->value){
        s = push(s,temp->value);
        temp = temp->parent;
    }
    s = push(s,pos_start->value);
    stack_t *curr = s;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int path_length(tree_t *t,int start,int finish){
    stack_t *s = NULL;
    node_t *pos_start = searchPos(t,start);
    node_t *pos_finish = searchPos(t,finish);
    node_t *temp = pos_finish;
    while(temp->value!=pos_start->value){
        s = push(s,temp->value);
        temp = temp->parent;
    }
    s = push(s,pos_start->value);
    stack_t *curr = s;
    int cnt=0;
    while(curr!=NULL){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}

void ancestor(tree_t *t,int finish){
    stack_t *s = NULL;
    node_t *pos_finish = searchPos(t,finish);
    node_t *temp = pos_finish;
    while(is_root(t,temp->value)!=1){
        s = push(s,temp->value);
        temp = temp->parent;
    }
    s = push(s,temp->value);
    stack_t *curr = s;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void bfs(tree_t *);
void descendant(tree_t *t,int value){
    node_t *check = searchPos(t,value);
    bfs(check);
    printf("\n");
}

void bfs(tree_t *t) {
    if (t == NULL) {
        return;
    }
    typedef struct QueueNode {
        tree_t *data;
        struct QueueNode *next;
    } QueueNode;
    QueueNode *front = NULL;
    QueueNode *rear = NULL;
    QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
    newnode->data = t;
    newnode->next = NULL;
    front = rear = newnode;

    while (front!=NULL) {
        tree_t *current = front->data;
        QueueNode *temp = front;
        front = front->next;
        free(temp);

        printf("%d ", current->value);

        tree_t *child = current->first_child;
        while (child != NULL) {
            newnode = (QueueNode *)malloc(sizeof(QueueNode));
            newnode->data = child;
            newnode->next = NULL;
            if (front == NULL) {
                front = rear = newnode;
            } else {
                rear->next = newnode;
                rear = newnode;
            }
            child = child->next_sibling;
        }
    }
}

void dfs(tree_t *t){
    printf("%d ",t->value);
    if(t->first_child!=NULL){
        dfs(t->first_child);
    }
    if(t->next_sibling!=NULL){
        dfs(t->next_sibling);
    }
}

void print_tree(tree_t *t){
    int space = t->depth;
    while(space--) printf("    ");
    printf("%d\n",t->value);
    if(t->first_child!=NULL){
        print_tree(t->first_child);
    }
    if(t->next_sibling!=NULL){
        print_tree(t->next_sibling);
    }
}

int main(void)
{
    tree_t *t = NULL;
    int n, i, command;
    int parent, child, node, start, end;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d %d", &parent, &child);
            t = attach(t, parent, child);
            break;
        case 2:
            scanf("%d", &node);
            t = detach(t, node);
            break;
        case 3:
            scanf("%d", &node);
            printf("%d\n", search(t, node));
            break;
        case 4:
            scanf("%d", &node);
            printf("%d\n", degree(t, node));
            break;
        case 5:
            scanf("%d", &node);
            printf("%d\n", is_root(t, node));
            break;
        case 6:
            scanf("%d", &node);
            printf("%d\n", is_leaf(t, node));
            break;
        case 7:
            scanf("%d", &node);
            siblings(t, node);
            break;
        case 8:
            scanf("%d", &node);
            printf("%d\n", depth(t, node));
            break;
        case 9:
            scanf("%d %d", &start, &end);
            print_path(t, start, end);
            break;
        case 10:
            scanf("%d %d", &start, &end);
            printf("%d\n",path_length(t, start, end));
            break;
        case 11:
            scanf("%d", &node);
            ancestor(t, node);
            break;
        case 12:
            scanf("%d", &node);
            descendant(t, node);
            break;
        case 13:
            bfs(t);
            break;
        case 14:
            dfs(t);
            break;
        case 15:
            print_tree(t);
            break;
        }
    }
    return 0;
}