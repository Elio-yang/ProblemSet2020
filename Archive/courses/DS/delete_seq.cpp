#include <stdlib.h>
#include <stdio.h>

#define data_t int
#define maxn   76
#define minn   24

struct node{
    data_t key;
    struct node* next;
};
int delele_seq(struct node*head,int mink,int maxk);
struct node *creat();
void insert(struct node *head,int key);
void display(struct node *head);
int main()
{
    /*表头*/
    struct node *head=creat();
    for(int i=100;i>0;i--){
       insert(head,i);
    }
    printf("添加前链表:\n");
    display(head);
    printf("删除区间23~73:\n");
    delele_seq(head,23,73);
    display(head);
    printf("删除区间5~5:\n");
    delele_seq(head,5,5);
    display(head);
    printf("删除区间9~8:\n");
    delele_seq(head,9,9);
    display(head);
    printf("删除区间101~120:\n");
    delele_seq(head,101,120);
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
int delele_seq(struct node*head,int mink,int maxk)
{
    if(mink>maxk){
        return -1;
    }
    struct node* tmp=head->next;
    struct node* prev;
    while(tmp!=NULL&&tmp->key<mink){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==NULL){
        return -1;
    }
    /*tmp->key=mink*/
    while(tmp->key<=maxk){
        prev->next=tmp->next;
        struct node *tmp_n=tmp;
        tmp=tmp->next;
        free(tmp_n);
    }
    return 1;
}