/*
 * ELIO YANG
 * JLU
 * 2020/12/07
 * provides Union-Find structure & algorithms
 * */

#include <cstdio>
const int maxn=1000;

class UionFind{
        int n;
        int Set[maxn]{};
        int num_cted;
        explicit UionFind(int N):n(N),num_cted(0){
                for (int i = 0; i < n; i++) {
                        Set[i]=i;
                }
        }
        bool connected(int x,int y);
        void merge(int x,int y);
        int find(int x);
        int count();
};
bool UionFind::connected(int x, int y)
{

        return find(x)==find(y);
}
void UionFind::merge(int x, int y)
{
        Set[y]=x;
}
int UionFind::find(int x)
{
        return (Set[x]==x)?(x):(Set[x]=find(Set[x]));
}

int UionFind::count()
{
        for (int i = 0; i < n; i++) {
                if (Set[i]==i){
                        num_cted++;
                }
        }
}

