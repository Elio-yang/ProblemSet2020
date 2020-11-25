/*
 编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，
 报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开
 始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列
 以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。
 */

#include <cstdio>

using namespace std;

struct node {
        int id;
        node *prev;
        node *next;

        node(int i) : id(i), prev(this), next(this)
        {}
};

struct student_circle {
        int size;
        node *p_stu;
        node *p_cur;

        explicit student_circle(int n) : size(n)
        {
                p_stu = new node(1);
                auto w = p_stu;
                p_cur = p_stu;
                for (int i = 2; i <= n; i++) {
                        auto stu = new node(i);
                        auto tmp = w->next;

                        stu->next = tmp;
                        stu->prev = w;
                        w->next = stu;
                        p_stu->prev = stu;
                        w = stu;
                }
        }

        int r_k(int k)
        {
                node *tmp;
                for (int i = 1; i < k; i++) {
                        tmp = p_cur;
                        p_cur = p_cur->next;
                }
                auto p_free = p_cur;
                auto p_tmp = p_cur->next;
                printf("%d ", p_cur->id);
                tmp->next = p_tmp;
                p_tmp->prev = tmp;
                p_cur = p_cur->next;
                delete p_free;
                size--;
        }

        int l_m(int m)
        {
                node *tmp;
                for (int i = 1; i < m; i++) {
                        tmp = p_cur;
                        p_cur = p_cur->prev;
                }
                auto p_free = p_cur;
                auto p_tmp = p_cur->prev;
                printf("%d ", p_cur->id);
                tmp->prev = p_tmp;
                p_tmp->next = tmp;
                p_cur = p_cur->prev;
                delete p_free;
                size--;
        }
        void play_game(int m,int k){
                for(;;){
                        if(size==0){
                                break;
                        }
                        l_m(m);
                        r_k(k);
                }
        }
};

int main()
{
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        student_circle circle(n);
        circle.play_game(m,k);
        return 0;
}

/*
#include<iostream>
#include<string.h>
using namespace std;

class Node{
public:
    char data;
    Node* next;
    Node* pre;
};
class LinkList{
//private:
public:
    Node* head;
    Node* tail;
public:
    LinkList();

    // void Insert(Node* p,char c);
    // void Change(Node* p,char c);
    // Node* Delete(Node* p);
    // void Show();
};

LinkList::LinkList(){
    head=new Node;
    tail=new Node;
    head->next=tail;
    head->pre=tail;
    tail->next=head;
    tail->pre=head;
}
// void LinkList::Insert(Node* p,char c){
//     Node* pnew=new Node;
//     pnew->data=c;
//     if(p->next==nullptr){
//         pnew->next=nullptr;
//         pnew->pre=p;
//         p->next=pnew;
//         return ;
//     }
//     pnew->pre=p;
//     p->next->pre=pnew;
//     pnew->next=p->next;
//     p->next=pnew;
// }
// void LinkList::Change(Node* p,char c){
//     p->next->data=c;
// }
// //!!!!!!!!!!!!!!!!!!!!!栈区栈区要清栈的
// //!!!!!!!!!!!!!!!!!!!!!!!!!!!千万注意返回值不能为void
// Node* LinkList::Delete(Node* p){
//     // Node* p1=p->pre;
//     // if(p->next==nullptr){
//     //     delete p; p=nullptr;
//     //     p=p1;
//     //     p->next=nullptr;
//     //     return p;
//     // }
//     p->pre->next=p->next;
//     p->next->pre=p->pre;
//     delete p; p=nullptr;
//     p=p1;
//     return p;
// }
// void LinkList::Show(){
//     Node* ptemp=this->head->next;
//     while(ptemp!=nullptr){
//         printf("%c",ptemp->data);
//         ptemp=ptemp->next;
//     }
// }
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    LinkList L;

    L.head->data=1;
    Node* p=L.head;
    Node* p0=L.tail;
    for(int i=2;i<=n-1;i++)
    {
        Node* pnew=new Node;
        pnew->data=i;

        pnew->next=p0;
        pnew->pre=p;
        p->next=pnew;
        p0->pre=pnew;

        p=p->next;
    }
    L.tail->data=n;

p=L.head;
while(1){
    //逆m-1
    for(int i=0;i<m-1;i++){
        p=p->pre;
    }
    Node* temp=p->pre;
    p->next->pre=temp;
    temp->next=p->next;
    printf("%d ",p->data); delete p; p=nullptr;
    p=temp;

    if(p->next==p&&p->pre==p) break;

    //顺k-1
    for(int i=0;i<k-1;i++){
        p=p->next;
    }
    Node* temp1=p->next;
    p->pre->next=p->next;
    p->next->pre=p->pre;
    printf("%d ",p->data); delete p; p=nullptr;
    p=temp1;

    if(p->next==p&&p->pre==p) break;

}

    printf("%d ",p->data);
    delete p; p=nullptr;
    //system("pause");
    return 0;

}
 */

