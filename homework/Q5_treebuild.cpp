#include <cstdio>
#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};
void in_order(struct node *root);
void post_order(struct node *root);
void pre_order(struct node *root);
void creat(struct node **T);

int main()
{
        struct node *T=(struct node *)malloc(sizeof(struct node));
        creat(&T);
        pre_order(T);
        std::cout<<std::endl;
        in_order(T);
        std::cout<<std::endl;
        post_order(T);
        return 0;
}

void in_order(struct node *root)
{
        if(root!=NULL){
                in_order(root->lchild);
                printf("%d ",root->key);
                in_order(root->rchild);
        }
}
void post_order(struct node *root)
{
        if(root!=NULL){
                post_order(root->lchild);
                post_order(root->rchild);
                printf("%d ",root->key);
        }
}
void pre_order(struct node *root)
{
        if(root!=NULL){
                printf("%d ",root->key);
                pre_order(root->lchild);
                pre_order(root->rchild);
        }
}
void creat(struct node **T)
{
        int k;
        std::cin>>k;
        if(*T==NULL){
                *T=(struct node *)malloc(sizeof(struct node));
        }
        if(k==0){
                *T=NULL;
        }else{
                (*T)->key=k;
                creat(&((*T)->lchild));
                creat(&((*T)->rchild));
        }
}