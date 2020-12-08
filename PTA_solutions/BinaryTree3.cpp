/*
二叉树路径和II

编写程序找出非空二叉树中和最大的路径，二叉树结点为不等于0的整数。
 本题的“路径”定义为二叉树中的结点序列*v**i*,...,*v**j*，
 序列中前一个结点是后一个结点的父结点，但路径不一定是以根结点为起点，
 也不一定是以叶结点为终点。路径的和定义为该路径所包含的所有结点的数据值之和。

输入格式:

输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。

输出格式:

输出为两行，第一行为该二叉树路径和的最大值，第二行为一组整数，每个整数后一个空格，表示该最大路径包含的结点值（按所在层数递增顺序输出）。如果存在多条满足条件的路径，则输出最短（包含结点个数最少）者，如果存在多条最短的路径，则输出最靠左上者。

输入样例1:

```in
1 2 0 0 3 0 0
```

输出样例1:

```out
4
1 3
```

输入样例2:

```in
-1 2 0 0 3 4 0 0 0
```

输出样例2:

```out
7
3 4
```

输入样例3:

```in
3 2 0 0 -1 4 0 0 0
```

输出样例3:

```out
6
3 -1 4
```
*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<vector<int> > vi;
vector<vector<int> > dp;
vector<int> vout;

class Node{
public:
        int data;
        Node* lChild;
        Node* rChild;
};
class Btree{
public:
        Node* root;
public:
        Btree();
        Node* pre_Creat();
        void tran(unsigned int pos,Node* proot);
};
Btree::Btree(){
        root=nullptr;
}
Node* Btree::pre_Creat(){
        int val; cin>>val;
        if(val==0)  return nullptr;

        Node* current=new Node;
        current->data=val;
        current->lChild=pre_Creat();
        current->rChild=pre_Creat();
        return current;
}
void Btree::tran(unsigned int pos,Node* proot){
        if(pos==vout.size()) vout.push_back(proot->data);
        else{
                while(pos!=vout.size()){
                        vout.pop_back();
                        //cout<<pos<<" "<<vout.size();
                        if(pos==vout.size()) break;
                }
                vout.push_back(proot->data);
        }
        if(proot->lChild==nullptr&&proot->rChild==nullptr){
                vi.push_back(vout);
        }
        else{
                if(proot->lChild!=nullptr) tran(pos+1,proot->lChild);
                if(proot->rChild!=nullptr) tran(pos+1,proot->rChild);
        }
}
int Max(int a,int b){
        if(a>b) return a;
        else return b;
}
//!!! j 还是 k
int MIN(int i,int j,int k){
        //dp[i][k] dp[i][j]
        int sum=0; int len=0;
        vector<int>::iterator it=vi[i].begin()+k;
        while(1){
                //cout<<*it<<" ";
                sum+=*it; it++; len++;
                if(sum==dp[i][k]) break;
        }

        int sum1=0; int len1=0;
        vector<int>::iterator it1=vi[i].begin()+j;
        while(1){
                sum1+=*it1; it1++; len1++;
                if(sum1==dp[i][j]) break;
        }

        if(len==len1) return k;
        if(len>len1) return j;
        if(len<len1) return k;

}
//!!!
void DP(){
        for(int i=0;i<vi.size();i++){
                dp.push_back(vi[i]);
        }
        for(int i=0;i<dp.size();i++){
                for(int j=dp[i].size()-2;j>=0;j--){
                        dp[i][j]=Max(dp[i][j+1]+dp[i][j],dp[i][j]);
                        //cout<<dp[i][j]<<" ";
                }
                //cout<<endl;
        }
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[i].size();j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }

        //!!
        int max[dp.size()]; //cout<<dp[1].size()<<endl;
        for(int i=0;i<dp.size();i++){
                int k=0;
                for(int j=1;j<dp[i].size();j++){
                        //!!!!!!!!!!!!!!这个特殊情况没考虑细心
                        // if(dp[i][j]>dp[i][k]){
                        //     k=j;
                        // }
                        if(dp[i][j]>dp[i][k]){
                                k=j; continue;
                        }
                        if(dp[i][j]==dp[i][k]){
                                k=MIN(i,j,k); continue;
                        }
                }
                max[i]=k; //保存的是下标
                //cout<<k<<" ";
        }
        //cout<<max[0]<<" "<<max[1]<<" "<<max[2]<<" "<<max[3]<<endl;
        //cout<<max[0]<<" "<<max[1]<<endl;
        //!!!
        int k=0; bool yiyang[dp.size()];
        memset(yiyang,0,dp.size()); yiyang[k]=true;
        for(int i=1;i<dp.size();i++){
                if(dp[i][max[i]]>dp[k][max[k]]){
                        memset(yiyang,0,dp.size());
                        yiyang[i]=true; k=i;
                }
                if(dp[i][max[i]]==dp[k][max[k]]) yiyang[i]=true;
        }
        //cout<<k<<endl; //指的是最大的是dp[k]这条路径   k是第几条路径 max[k]是从哪开始
        cout<<dp[k][max[k]]<<endl;
        //cout<<yiyang[0]<<" "<<yiyang[1]<<endl;

        //!!!
        vector<int> cntarr;
        for(int i=0;i<dp.size();i++){
                if(yiyang[i]==true) cntarr.push_back(i);
        }
        //cout<<cntarr[0]<<" "<<cntarr[1]<<endl;
        vector<int>::iterator it=cntarr.begin();
        int lenall=0x3f3f3f; int index;
        while(it!=cntarr.end()){
                int sum=0; int len=0;
                vector<int>::iterator it1=vi[*it].begin()+max[*it];
                while(sum!=dp[*it][max[*it]]){
                        sum+=*it1; it1++; len++;
                }//len字串的长度
                if(len<lenall){lenall=len; index=*it;}
                it++;
        }
        k=index;
        //!!!相同的个数
        //cout<<dp[1][0]<<" "<<vi[1][0];



        //cout<<dp[0].size()<<" "<<vi[0].size();
        //!!

        int k1=max[k];
        for(int i=0;i<lenall;i++){
                printf("%d ",vi[k][k1]);
                k1++;
        }
        cout<<endl;
        // while(1){
        //     if(dp[k][k1]==vi[k][k1]){
        //         printf("%d ",dp[k][k1]);
        //         break;
        //     }
        //     else{
        //         printf("%d ",vi[k][k1]);
        //         k1++;
        //     }
        // }
        // cout<<endl;

}


int main(){
        Btree B;
        B.root=B.pre_Creat();
        B.tran(0,B.root);

        // for(int i=0;i<vi.size();i++){
        //     for(int j=0;j<vi[i].size();j++)
        //         cout<<vi[i][j]<<" ";
        //     cout<<endl;
        // }
        //cout<<endl;
        DP();



        system("pause");
        return 0;
}
/*

3 -2 4 0 5 0 0 0 1 0 0
3 2 0 0 -1 4 0 0 0
-1 2 0 0 3 4 0 0 0
-1 -1 0 0 -1 4 0 0 0
1 2 0 0 3 0 0

3 1 1 0 0 0 2 0 0

-1 2 1 0 1 0 0 0 -2 3 0 1 0 0 4 0 0

5 -7 10 0 0 0 2 1 0 0 -6 11 0 0 13 0 0
6 -7 3 0 0 5 0 0 4 7 0 0 -5 0 0
9 -13 7 0 0 0 -7 6 0 0 -2 5 4 1 0 0 0 0 8 0 0

9 1 -1000 8 2 0 0 0 0 0 1 0 -1000 0 7 0 3 0 0

9 -13 7 0 0 0 -7 6 0 0 -2 5 4 1 0 0 0 0 8 2 -2 2 0 0 0 0 0

-1 2 1 0 1 0 0 0 -2 3 0 1 0 0 4 0 0



//!!!!!!!!!!!!!!!!!!!!!千万注意一条路径上也有相同的子序列千万注意