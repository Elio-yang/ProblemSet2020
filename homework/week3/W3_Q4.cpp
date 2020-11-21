#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define is_leaf(x) (((x)->lc==nullptr)&&((x)->rc==nullptr))
struct node{
        int key;
        struct node *lc;
        struct node *rc;
};
using namespace std;
struct node* creat();
int max_sum=INT32_MIN;
vector<int> path;
vector<int> max_path;
//int dfs(struct node *T,int cur_sum,int& max_sum,vector<int>&max_path,vector<int>&path);
int dfs(node*T);
int main()
{
        struct node* T;
        T=creat();
        int max_sum=dfs(T);
        cout<<max_sum;
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
int dfs(node*T)
{

}