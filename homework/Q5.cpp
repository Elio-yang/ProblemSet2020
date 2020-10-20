#include <cstdio>
#include <cstdlib>

struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};


void in_order(struct node *root);
void post_order(struct node *root);
void pre_order(struct node *root);
void creat(struct node *T);

int main()
{
        struct node *T;
        creat(T);
        return 0;
}

void in_order(struct node *root);
void post_order(struct node *root);
void pre_order(struct node *root);
void creat(struct node *T)
{
        int k;
        scanf("%d",&k);
        struct node *T=(struct node *)malloc(sizeof(struct node));
        if(k==0){
                T=NULL;
        }else{
                T->key=k;
                creat(T->lchild);
                creat(T->rchild);
        }
}