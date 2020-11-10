#include <cstdlib>
#include <iostream>
struct node{
        char key;
        struct node *lchild;
        struct node *rchild;
};

struct node* creat();
void LevelCnt(struct node *T,int l,int level_cnt[]);
int level(struct node *T);
#define has_only_lc(x) (((x)->lchild)&&!((x)->rchild))
#define has_only_rc(x) (((x)->rchild)&&!((x)->lchild))
#define has_only_ac(x) (has_only_lc(x)||has_only_rc(x))


int main()
{
        auto *T=(struct node *)malloc(sizeof(struct node));
        T=creat();

        int level_cnt[110]={0};
        int l=0;
        LevelCnt(T,l,level_cnt);
        int level_t=level(T);
        for(int i=0;i<level_t;i++){
                std::cout<<level_cnt[i]<<std::endl;
        }
        return 0;
}

struct node* creat()
{
        char k;
        scanf("%c",&k);
        struct node* T;

        if(k=='#'){
                T= NULL;
        }else{
                T=(struct node*)malloc(sizeof(struct node));
                T->key=k;
                T->lchild=creat();
                T->rchild=creat();
        }
        return T;
}
void LevelCnt(struct node *T,int l,int level_cnt[])
{
        if(T){
                if(has_only_ac(T)){
                        ++level_cnt[l];
                }
                LevelCnt(T->lchild,l+1,level_cnt);
                LevelCnt(T->rchild,l+1,level_cnt);
        }
        return;
}
int level(struct node *T)
{
        if(T==NULL){
                return 0;
        }
        return 1+std::max(level(T->lchild),level(T->rchild));
}

