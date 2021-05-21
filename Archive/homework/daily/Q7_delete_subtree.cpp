#include <cstdio>
#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};
void in_order(struct node *root);
void creat(struct node **T);
void find_node(struct node **T,int key);
void delete_sub(struct node *T);
bool flag=false;
int main()
{
        struct node *T=(struct node *)malloc(sizeof(struct node));
        creat(&T);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
                int k;
                flag=0;
                scanf("%d",&k);
                find_node(&T,k);
                if(!flag){
                        std::cout<<0<<std::endl;
                }else{
                        in_order(T);
                        std::cout<<std::endl;
                }
    }
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
void find_node(struct node **T,int key)
{
        if((*T)->key==key){
                flag=true;
                delete_sub(*T);
                *T=NULL;
        }
        else{
                if((*T)->lchild){
                        find_node(&((*T)->lchild),key);
                }
                if((*T)->rchild){
                        find_node(&(*T)->rchild,key);
                }
        }
}
void delete_sub(struct node *T)
{
        if(T->lchild){
                delete_sub(T->lchild);
        }
        if(T->rchild){
                delete_sub(T->rchild);
        }
        free(T);
}