#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
bool hash_table[maxn]={false};
int main()
{
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        hash_table[x]=true;
    }
    /*很重要的搞法：下标作为性质*/
    for(int i=0;i<m;i++){
        cin>>x;
        if(hash_table[x]==true){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    /* 
     * 散列：将一个元素（key）通过函数（散列函数H）转化为整数，使得
     * 这个整数可以尽量唯一的代表这个元素
     */
    return 0;
}