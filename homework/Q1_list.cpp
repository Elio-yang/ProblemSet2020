#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
int size;
struct node* creat(int *arr,int length);
void insert_node(struct node* head,int k,int d);
void delete_node(struct node* head,int k);
void display(struct node *head);
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    /*第一行*/
    int n;
    scanf("%d",&n);
    /*第二行*/
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    /*第三行*/
    int m;
    scanf("%d",&m);

    head=creat(arr,sizeof(arr)/sizeof(arr[0]));
    //display(head);
    int op1;
    int k;
    int d;
    for(int i=0;i<m;i++){
        scanf("%d",&op1);
        if(op1==0){
            scanf("%d %d",&k,&d);
            insert_node(head,k,d);
        }
        else if(op1==1){
            scanf("%d",&k);
            delete_node(head,k);
        }
    }
    display(head);
    //system("pause");
    return 0;
}
struct node *creat(int *arr,int length)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=0;
    node->next=NULL;
    for(int i=0;i<length;i++){
        insert_node(node,0,arr[length-1-i]);
    }
    return node;
}
/*在第k个节点后面插入，k=0是表头*/
void insert_node(struct node* head,int k,int d)
{
    if(k>size){
        return ;
    }
    struct node* tmp=head;
    int cnt;
    for(cnt=0;cnt<k;cnt++){
        tmp=tmp->next;
    }
    struct node* tmp2=tmp->next;
    struct node* new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=d;
    tmp->next=new_node;
    new_node->next=tmp2;
    ++size;
}
void display(struct node* head)
{
    struct node *tmp=head->next;
    int cnt=-1;
    while(tmp!=NULL){
        ++cnt;
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}
void delete_node(struct node* head,int k)
{
    if(k==0||k>size){
        return ;
    }
    struct node* tmp=head;
    int cnt;
    for(cnt=1;cnt<k;cnt++){
        tmp=tmp->next;
    }
    struct node* des=tmp->next;
    struct node* tmp2=des->next;
    tmp->next=tmp2;
    des->next=NULL;
    free(des);
}