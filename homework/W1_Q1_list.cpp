#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define maxn 50010

struct node{
        char c;
        struct node *next;
        struct node *before;
};

void build_list(char str[],struct node*& head)
{
        bool insert_flag=false;
        struct node *p=head;
        for(int i=0;str[i]!='\0';i++){
                char ch=str[i];
                
                switch(ch){
                        case '[':{
                                p=head;
                                break;
                        }
                        case ']':{
                                for(;p->next!=NULL;p=p->next){
                                        
                                }
                                break;
                        }
                        case '{':{
                                if(p!=head){
                                        p=p->before;
                                }
                                break;
                        }
                        case '}':{
                                if(p->next!=NULL){
                                        p=p->next;
                                }
                                break;
                        }
                        case '-':{
                                insert_flag=!insert_flag;
                                break;
                        }
                        case '=':{
                                p->before->next=p->next;
                                if(p->next){
                                        p->next->before=p->before;
                                }
                                struct node *tmp=p;
                                free(tmp);
                                p=p->before;
                                break;
                        }
                        default:{
                                if(insert_flag){
                                        p->next->c=ch;
                                        p=p->next;
                                }else{
                                        struct node *p_t=(struct node*)malloc(sizeof(struct node));
                                        p_t->c=ch;
                                        p_t->next=NULL;
                                        p_t->before=NULL;
                                        p_t->next=p->next;
                                        p_t->before=p;
                                        if(p_t->next!=NULL){
                                                p_t->next->before=p_t;
                                        }
                                        p->next=p_t;
                                        p=p->next;
                                }
                                break;
                        }
                                
                }
                
        }
}

void release_list(struct node *head)
{
        while(head!=NULL){
                struct node *tmp=head;
                free(tmp);
                head=head->next;
        }
}

int main()
{
        char str[maxn];
        char c;
        int j=0;
        while((c=getchar())!='\n'){
                str[j++]=c;
        }
        str[j]='\0';

        struct node* head;
        head=(struct node*)malloc(sizeof(struct node));
        head->next=NULL;
        head->before=NULL;
        head->c='\0';
        build_list(str,head);
        struct node* p_h=head->next;
        while(p_h!=NULL){
                printf("%c",p_h->c);
                p_h=p_h->next;
        }
        release_list(head);
        return 0;
}