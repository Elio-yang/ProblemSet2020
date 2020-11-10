#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};
using namespace std;
struct node* creat();
int max_sum=INT32_MIN;
int dfs(struct node *T);

int main()
{
        struct node* T;
        T=creat();
        int max_v=dfs(T);
        cout<<max_v;
        return 0;
}
struct node* creat()
{
        int k;
        scanf("%d",&k);
        struct node* T;

        if(k==0){
                T= NULL;
        }else{
                T=(struct node*)malloc(sizeof(struct node));
                T->key=k;
                T->lchild=creat();
                T->rchild=creat();
        }
        return T;
}
int dfs(struct node *T)
{
        if(T==NULL){
                return 0;
        }
        int lc_l=dfs(T->lchild);
        int rc_l=dfs(T->rchild);
        int sum=T->key;
        if(lc_l>0){sum+=1;}
        if(rc_l>0){sum+=1;}
        max_sum=std::max(max_sum,sum);
        return max(lc_l,rc_l)>0?max(rc_l,lc_l)+T->key:T->key;
}


