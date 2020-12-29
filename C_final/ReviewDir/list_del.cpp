//
// Created by ELIO on 2020/12/29.
//
#include <stdio.h>
#include <malloc.h>
struct node{
        int key;
        struct node *next;
};


//删除奇数节点
struct node* del_odd(struct node* head)
{
        struct node * cur=head;
        struct node * prev=NULL;

        while (cur != NULL){
                if (cur->key % 2 == 1){
                        if (prev != NULL){//非头节点
                                prev->next=cur->next;
                        }else{
                                head=cur->next;
                        }
                }
                else{
                        prev=cur;
                }
                cur=cur->next;
        }
        return head;
}

//删除值为x的节点
struct node* del_x(struct node* head,int x)
{
        struct node * cur=head;
        struct node * prev=NULL;

        while (cur!=NULL)
        {
                while (cur!=NULL&&cur->key!=x){
                        prev=cur;
                        cur=cur->next;
                }

                //cur->key==x
                if (cur!=NULL){
                      cur=cur->next;
                      if(prev!=NULL){
                              prev->next=cur;
                      }else{
                              head=cur;
                      }
                }
        }
        return head;
}

//删除后继小于前驱的节点
void del_sm(struct node *head)
{
        if (head==NULL){return ;}
        struct node* prev=head;
        struct node* cur=head->next;
        while (cur!=NULL){
                if (prev->key>=cur->key){
                        prev->next=cur->next;
                        cur=cur->next;
                }else{
                        prev=cur;
                        cur=cur->next;
                }
        }
}








