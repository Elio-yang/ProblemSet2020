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
void find_fa(BiTree &root,int son,int *father);
int main(){
    BiTree T;
    creat(T);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int tmp;
        scanf("%d",&tmp);
        int father=0;
        find_fa(T,tmp,&father);
        cout<<father<<endl;
    }
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
void find_fa(BiTree &root,int son,int *father)
{
    if(root==NULL){
        return;
    }
    if((root->lchild!=NULL&&root->lchild->data==son)||(root->rchild!=NULL&&root->rchild->data==son)){
        *father=root->data;
        return;
    }
    if(root->lchild==NULL&&root->rchild==NULL){
        return;
    }
    find_fa(root->lchild,son,father);
    find_fa(root->rchild,son,father);
}
