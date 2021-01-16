#include <stdio.h>
#include <malloc.h>
struct cell {//单链表结点结构体定义
        int x;
        struct cell* next;
};
struct cell* build(void) {//新建单链表，并将建好的单链表首结点地址返回
        struct cell* head, * tmp, * tail;
        head = tmp = tail = NULL;
        int n, i;
        head=(struct cell*)malloc(sizeof(struct cell));
        scanf("%d",&head->x);
        tmp=head;
        tmp->next=NULL;
        if(head->x==0)head=NULL;
        else{
                do{
                        tail=(struct cell*)malloc(sizeof(struct cell));
                        scanf("%d",&tail->x);
                        if(tail->x==0)break;
                        tmp->next=tail;
                        tmp=tail;
                        tmp->next=NULL;
                }while(tail->x!=0);
        }
        return head;//返回单链表头
}
struct cell* combine(struct cell* p, struct cell* q) {//合并两个链表p和q
        struct cell* head= NULL,*p0=NULL,*q0=NULL,*r=NULL;
        if (p == NULL && q!= NULL) return q;
        if (p != NULL && q == NULL) return p;
        if (p == NULL && q == NULL) return NULL;
        if(p!=NULL&&q!=NULL){
                head=p;
                while(head->next!=NULL){
                        head=head->next;
                }
                head->next=q;
                return p;
        }
}
void print(struct cell* head) {//打印整个单链表,head是单链表首结点指针
        struct cell *p,*p0,*r,*r0,*q;
        struct cell *k;
        p0=NULL;
        p=head;
        while(p!=NULL){
                r=head;
                while((r->x<p->x)&&r!=p){
                        r0=r;
                        r=r->next;
                }
                if(r!=p){
                        q=p;
                        p0->next=p->next;
                        p=p0;
                        if(r==head){
                                q->next=head;
                                head=q;
                        }else{
                                q->next=r;
                                r0->next=q;
                        }
                }
                p0=p;
                p=p->next;
        }
        printf("%d",head->x);
        k=head->next;
        while(k!=NULL){
                printf(" %d",k->x);
                k=k->next;
        }
}
void release(struct cell* head) {//释放单链表空间,head是单链表首结点指针
        struct cell *p;
        while(head!=NULL){
                p=head;
                head=p->next;
                free(p);
        }
}
int main(void) {
        struct cell* head1,*head2, *result;
        head1 = build();
        head2 = build();
        result = combine(head1,head2);
        if (result != NULL)
                print(result);
        else
                printf("NULL");
        release(result);
        return 0;
}