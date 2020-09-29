#include <iostream>
#include <cstdlib>
#define data_t int
using namespace std;
struct node{
    data_t key;
    struct node *next;
};

struct node * reverse_list(struct node* head);
int main()
{
    struct node node1={1,NULL};
    struct node node2={2,NULL};
    struct node node3={3,NULL};
    struct node node4={4,NULL};
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    struct node head={0,&node1};
    struct node* tmp=head.next;
    cout<<"原链表为：head->";
    while(tmp!=NULL){
        if(tmp->next==NULL){
        cout<<tmp->key;
        break;
        }
        cout<<tmp->key<<"->";
        tmp=tmp->next;
    }
    cout<<endl;

    struct node *head2=reverse_list(&head);
    struct node *tmp2=head2;
    cout<<"翻转链表为：head->";
    while(tmp2->next!=NULL){
        if(tmp2->next->next==NULL){
        cout<<tmp2->key;
        break;
        }
        cout<<tmp2->key<<"->";
        tmp2=tmp2->next;
    }
    cout<<endl;
    system("pause");
    return 0;
}
struct node * reverse_list(struct node* head)
{
    if(head==NULL||head->next==NULL){
        return head;
    }
    struct node* new_node;
    /*the last node(head->next)*/
    new_node=reverse_list(head->next);
    struct node *tmp=head->next;
    tmp->next=head;
    head->next=NULL;
    return new_node;
}