/*
 ## 运动会 (10分)

T公司的员工层级关系可以表示成一棵树，员工X是员工Y的直接领导，则在树中X是Y的父结点。公司拟组织一场运动会，但为了避免尴尬，每个员工都不想与自己的直接领导一起参赛。假定每个员工都对应一个权重（领导的权重不一定比下属大），请你编写程序，邀请若干员工参赛，使得参赛人员的总权重和最大。

### 输入格式:

第一行一个正整数n，表示公司的员工人数，员工编号为1...n，n不超过3000。 接下来n行，每行1个整数，表示每个员工的权重，值域为[−27,27)。 接下来n-1行，每行为两个空格间隔的整数X和Y，表示Y是X的直接领导。

### 输出格式:

输出为一个整数，表示参赛员工的最大权重之和。

### 输入样例:

```in
7
2
2
2
2
2
2
2
2 1
3 1
4 2
5 2
6 3
7 3
```

### 输出样例:

```out
10
```
*/

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

class Node{
public:
        int weight;
        vector<int> child;
};

#define maxn 3001
int dp[maxn][2]; //0 不选 1 选
Node node[maxn];
bool update[maxn]={false}; //false未更新
bool isSon[maxn]={false}; //true代表当过儿子

int Max(int a,int b){
        if(a>b) return a;
        else return b;
}

//求每一个child的dp[0] dp[1]的最大值 并把每一个child最大值加起来
int SonMaxSum(int i){
        int sum=0;
        for(unsigned int k=0;k<node[i].child.size();k++){
                sum+=Max(dp[node[i].child[k]][0],dp[node[i].child[k]][1]);
        }
        return sum;
}

//求所有child dp[0] 之和
int allson0(int i){
        int sum=0;
        for(unsigned int k=0;k<node[i].child.size();k++){
                sum+=dp[node[i].child[k]][0];
        }
        return sum;
}

//更新dp值
void DP(int i){
        if(node[i].child.empty()) return ;

        for(int j=0;j<node[i].child.size();j++){
                DP(node[i].child[j]);
        }
        dp[i][0]=SonMaxSum(i);
        dp[i][1]=node[i].weight+allson0(i);
}

int findRoot(int n){
        for(int i=1;i<=n;i++){
                if(isSon[i]==false) return i;
        }
        return 0; //实则不会从这return的
}

int main(){
        int n; scanf("%d",&n);
        int arr[n+1];
        for(int i=1;i<=n;i++){
                scanf("%d",&arr[i]);
                node[i].weight=arr[i];
        }
        for(int i=0;i<n-1;i++){
                int a,b; scanf("%d%d",&a,&b);
                node[b].child.push_back(a);
                isSon[a]=true;
        }

        for(int i=1;i<=n;i++){
                if(node[i].child.size()==0){
                        dp[i][0]=0; dp[i][1]=node[i].weight;
                        update[i]=true;
                }
        }//将第一层当作边界 边界设置完毕

        int root=findRoot(n);
        DP(root);
        // while(update[root]!=true){
        //     for(int i=n;i>=1;i--){
        //         if(node[i].child.size()!=0&&update[i]==false){
        //         if(update[i]==false){
        //             bool isupdate=false;
        //             for(unsigned int j=0;j<node[i].child.size();j++)
        //                 if(update[node[i].child[j]]==false)
        //                     isupdate=true;
        //             if(isupdate==false) DP(i);
        //         }
        //     }
        // }//while结束代表全部更新完毕

        cout<<Max(dp[root][0],dp[root][1])<<endl;


        system("pause");
        return 0;
}
/*
7
2
2
2
2
2
2
2
2 1
3 1
4 2
5 2
6 3
7 3

7
-2
-2
-2
-2
-2
-2
-2
2 1
3 1
4 2
5 2
6 3
7 3

7
-2
2
2
2
2
2
2
2 1
3 1
4 2
5 2
6 3
7 3

8
2
2
2
1
2
3
4
5
2 1
3 1
4 2
5 2
6 3
7 3
8 4

5
2
5
3
1
3
1 4
3 1
5 2
2 4

*/
