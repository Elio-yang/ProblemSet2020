#include <iostream>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    struct node* next;
};

struct node * creat(int key);
struct node * insert(int key,struct node *head);
struct node * find_before_n(struct node *head,struct node *src,int n);
struct node * find(struct node * head,int key);
int main()
{
    struct node * head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=creat(1);
    for(int i=2;i<10;i++){
        insert(i,head);
    }
    struct node* src=find(head,5);
    struct node* dest=find_before_n(head,src,4);
    cout<<dest->data<<endl;    
    system("pause");
    return 0;
}
struct node * creat(int key)
{
    struct node * new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=key;
    new_node->next=nullptr;
    return new_node;
}
struct node * insert(int key,struct node * head)
{
    struct node *tmp=head->next;
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=key;
    new_node->next=tmp;
    head->next=new_node;
    return head;
}
struct node * find_before_n(struct node *head, struct node *src,int k)
{
    /*双指针*/
    struct node *p1=head->next;
    struct node *p2=head->next;
    /*第k个节点*/
    for(int i=0;i<k;i++){
        p1=p1->next;
    }
    /*慢指针开始走*/
    for(;;){
        if(p1==src){
            break;
        }
        p1=p1->next;
        p2=p2->next;
    } 
    return p2;
}
struct node * find(struct node * head,int key)
{
    struct node *tmp=head;
    while(tmp!=nullptr){
        if(tmp->data==key){
            break;
        }
        tmp=tmp->next;
    } 
    return tmp;
}