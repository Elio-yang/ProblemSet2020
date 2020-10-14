#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>

using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

vector<BiTree> v;
void in_order(BiTree &root);
void creat(BiTree &T);
void find_node(BiTree &T,int key);
void delete_sub(BiTNode *node);

bool flag=0;

int main(){
    BiTree T;
    creat(T);
    int m;
    scanf("%d",&m);
    BiTNode node;
    for(int i=0;i<m;i++){
        int k;
        flag=0;
        scanf("%d",&k);
        find_node(T,k);
        if(!flag){
            cout<<0<<endl;
        }else{
            in_order(T);
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}
void in_order(BiTree &root)
{
    if(root!=NULL){
        in_order(root->lchild);
        printf("%d ",root->data);
        in_order(root->rchild);
    }
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
void find_node(BiTree &T,int key)
{
    if(T->data==key){
        flag=1;
        delete_sub(T);
        T=NULL;
    }else{
        if(T->lchild){
            find_node(T->lchild,key);
        }
        if(T->rchild){
            find_node(T->rchild,key);
        }
    }
}
void delete_sub(BiTNode *node)
{
    if(node->lchild){
        delete_sub(node->lchild);
    }
    if(node->rchild){
        delete_sub(node->rchild);
    }
    free(node);
}
