#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void in_order(BiTree &root);
void post_order(BiTree &root);
void pre_order(BiTree &root);
void creat(BiTree &T);

int main(){
    BiTree T;
    creat(T);
    pre_order(T);
    cout<<endl;
    in_order(T);
    cout<<endl;
    post_order(T);
    system("pause");
    return 0;
}
void creat(BiTree &T){
    int k;
    cin>>k;
    T=(BiTree )malloc(sizeof(BiTNode));
    if(k==0)T=NULL;
    else{
        T->data=k;
        creat(T->lchild);
        creat(T->rchild);
    }

}
void in_order(BiTree &root)
{
    if(root!=NULL){
        in_order(root->lchild);
        printf("%d ",root->data);
        in_order(root->rchild);
    }
}
void post_order(BiTree &root)
{
    if(root!=NULL){
        post_order(root->lchild);
        post_order(root->rchild);
        printf("%d ",root->data);
    }
}
void pre_order(BiTree &root)
{
    if(root!=NULL){
        printf("%d ",root->data);
        pre_order(root->lchild);
        pre_order(root->rchild);
    }
}
