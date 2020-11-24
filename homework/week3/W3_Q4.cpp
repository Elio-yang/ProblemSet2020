#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define is_leaf(x) (((x)->lc==nullptr)&&((x)->rc==nullptr))
struct vertex{
        int key;
        struct vertex *lc;
        struct vertex *rc;
};
using namespace std;
struct vertex* creat();
int max_sum=INT32_MIN;
vector<int> path;
vector<int> max_path;
//int dfs(struct node *T,int cur_sum,int& max_sum,vector<int>&max_path,vector<int>&path);
int dfs(vertex*T);
int main()
{
        struct vertex* T;
        T=creat();
        int max_sum=dfs(T);
        cout<<max_sum;
        return 0;
}
struct vertex* creat()
{
        int k;
        scanf("%d",&k);
        struct vertex* T;

        if(k==0){
                T= NULL;
        }else{
                T=(struct vertex*)malloc(sizeof(struct vertex));
                T->key=k;
                T->lc=creat();
                T->rc=creat();
        }
        return T;
}
//int dfs(struct node *T,int cur_sum,int& max_sum,vector<int>&max_path,vector<int>&path)
//{
//        cur_sum+=T->key;
//        path.push_back(T->key);
//        if(is_leaf(T)&&)
//}
int dfs(vertex*T)
{

}