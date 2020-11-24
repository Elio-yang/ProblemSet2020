#include <cstdlib>
#include <iostream>
struct vertex{
        char key;
        struct vertex *lc;
        struct vertex *rc;
};

struct vertex* creat();
void LevelCnt(struct vertex *T, int l, int level_cnt[]);
int level(struct vertex *T);
#define has_only_lc(x) (((x)->lchild)&&!((x)->rchild))
#define has_only_rc(x) (((x)->rchild)&&!((x)->lchild))
#define has_only_ac(x) (has_only_lc(x)||has_only_rc(x))


int main()
{
        auto *T=(struct vertex *)malloc(sizeof(struct vertex));
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

struct vertex* creat()
{
        char k;
        scanf("%c",&k);
        struct vertex* T;

        if(k=='#'){
                T= NULL;
        }else{
                T=(struct vertex*)malloc(sizeof(struct vertex));
                T->key=k;
                T->lc=creat();
                T->rc=creat();
        }
        return T;
}
void LevelCnt(struct vertex *T, int l, int level_cnt[])
{
        if(T){
                if(has_only_ac(T)){
                        ++level_cnt[l];
                }
                LevelCnt(T->lc, l + 1, level_cnt);
                LevelCnt(T->rc, l + 1, level_cnt);
        }
        return;
}
int level(struct vertex *T)
{
        if(T==NULL){
                return 0;
        }
        return 1+std::max(level(T->lc), level(T->rc));
}

