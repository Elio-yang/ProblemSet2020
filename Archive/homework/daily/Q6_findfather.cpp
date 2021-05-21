#include <cstdio>
#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};

void creat(struct node **T);
void find_pa(struct node *T,int son,int *pa);
int main()
{
        struct node *T=(struct node *)malloc(sizeof(struct node));
        creat(&T);
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
                int tmp;
                scanf("%d",&tmp);
                int pa=0;
                find_pa(T,tmp,&pa);
                std::cout<<pa<<std::endl;
        }
        return 0;
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

void find_pa(struct node *T,int son,int *pa)
{
        if(T==NULL){
                return;
        }
        if((T->lchild!=NULL&&T->lchild->key==son)||(T->rchild!=NULL&&T->rchild->key==son)){
                *pa=T->key;
                return;
        }
        if(T->lchild==NULL&&T->rchild==NULL){
                return;
        }
        find_pa(T->lchild,son,pa);
        find_pa(T->rchild,son,pa);
}