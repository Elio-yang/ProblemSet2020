#include <stdlib.h>
#include <stdio.h>

#define data_t int
#define S      9987
#define T      1008
struct node{
    data_t key;
    struct node* next;
};

struct node *creat();
void insert(struct node *head,int key);
void op_list(struct node *head);
void display(struct node *head);
struct node *find_prev(struct node *head, struct node *node);
int main()
{
    /*表头*/
    struct node *head=creat();
    for(int i=0;i<100;i++){
        if(i%2==0){
            insert(head,S);
        }else{
            insert(head,i);
        }
    }
    printf("添加前链表:\n");
    display(head);
    printf("添加后链表:\n");
    op_list(head);
    display(head);

    system("pause");
    return 0;
}

struct node *creat()
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->key=0;
    node->next=NULL;
    return node;
}
/*在head后进行插入*/
void insert(struct node* head, int key)
{   
    struct node* new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->key=key;
    new_node->next=head->next;
    head->next=new_node;
}
void op_list(struct node *head)
{
    struct node *tmp=head->next;
    while(tmp!=NULL){
        if(tmp->next!=NULL&&tmp->next->key==S){
            struct node *prev;
            prev=find_prev(head,tmp->next);
            struct node *next=prev->next;
            /*保存前后件*/
            struct node *new_node=(struct node *)malloc(sizeof(struct node));
            prev->next=new_node;
            new_node->next=next;
            new_node->key=T;
            tmp=next;
        }
        else{
            tmp=tmp->next;
        }
    }

}
void display(struct node* head)
{
    struct node *tmp=head->next;
    int cnt=-1;
    while(tmp!=NULL){
        ++cnt;
        printf("%-6d    ",tmp->key);
        if(cnt%10==9){
            printf("\n");
        }
        tmp=tmp->next;
    }
    printf("\n");
}
struct node* find_prev(struct node* head,struct node *node)
{
    struct node *tmp=head->next;
    while(tmp!=NULL){
        if(tmp->next==node){
            return tmp;
        }
        tmp=tmp->next;
    }
    return NULL;    
}