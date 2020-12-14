/*
 ## 树最大乘积路径 (10分)

已知树结点为不等于0的整数。编写程序找出非空树中乘积最大的路径。
 本题的“路径”定义为树中的结点序列*v**i*,...,*v**j*，
 序列中前一个结点是后一个结点的父结点，但路径不一定是以根结点为起点，
 也不一定是以叶结点为终点。路径的乘积定义为该路径所包含的所有结点的数据值之积。
 例如对于图1(a)所示的树t，乘积最大的路径为8-5-6。

![tree.jpg](https://images.ptausercontent.com/1a9f60fd-4937-4fb8-8b72-1d2bb0d98162.jpg)

### 输入格式:

输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列，其中空指针信息用0表示。

注：我们已知二叉树与其自然对应的树相比，二叉树中结点的左孩子对应树中结点的左孩子，二叉树中结点的右孩子
 对应树中结点的右兄弟。进而我们可以利用“基于引入空指针信息的先根序列构建二叉树”的方法来构建其对应的树的
 左孩子-右兄弟存储结构。如8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0对应图1(a)所示的树，1 2 0 3 0 4 0 0 0
 对应如图1(b)所示的树。

### 输出格式:

输出为两行，第一行为该树的路径乘积的最大值，第二行为一组空格间隔的整数，
 即该最大乘积路径包含的结点值（按所在层数递增顺序输出）。如果存在多条满足条件的路径，
 则输出最短（包含结点个数最少）者，如果存在多条最短的路径，则输出最靠左上者。

### 输入样例1:

```in
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
```

### 输出样例1:

```out
240
8 5 6
```

### 输入样例2:

```in
1 2 0 3 0 4 0 0 0
```

### 输出样例2:

```out
4
4
```
*/

#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class node{
public:
        int data;
        int dp;
        node* lChild;
        node* rbro;
        node* father;
public:
        node(): lChild(nullptr), rbro(nullptr), father(nullptr){}
};
class Tree{
public:
        node* root;
public:
        Tree(){root=nullptr;}
        node* pre_Creat(node* p);
        node* layerdp();
};
node* Tree::pre_Creat(node* p){
        int val; scanf("%d",&val);
        if(val==0) return nullptr;

        node* cur=new node;
        cur->data=val;
        cur->dp=val;
        cur->father=p;
        cur->lChild=pre_Creat(cur);
        cur->rbro=pre_Creat(cur->father);
        return cur;
}
int Max(int a,int b){
        if(a>b) return a;
        else return b;
}
int Len(node* proot){
        int len=0; int mulity=1; int dp=proot->dp;
        while(mulity!=dp){
                mulity=mulity*proot->data;
                proot=proot->father;
                len++;
        }
        return len;
}
node* Tree::layerdp(){
        if(this->root!=nullptr){
                queue<node*> q; q.push(this->root);
                int max1=this->root->dp; node* proot=this->root;
                while(!q.empty()){
                        node* p=q.front(); q.pop();
                        if(p->father!=nullptr){
                                //p->dp=Max(p->dp,p->dp*(p->father->dp));
                                p->dp=p->dp*(p->father->dp);
                                if(p->dp>proot->dp){
                                        max1=p->dp; proot=p;
                                }
                                if(p->dp==proot->dp){
                                        if(Len(p)<Len(proot)){
                                                max1=p->dp; proot=p;
                                        }
                                }
                        }
                        p=p->lChild;
                        while(p!=nullptr){
                                q.push(p);
                                p=p->rbro;
                        }
                }
                return proot;
        }
}

int main(){
        Tree T; T.root=T.pre_Creat(nullptr);
        node* p=T.layerdp();
        printf("%d\n",p->dp);

        int length=Len(p); int arr[length];
        for(int i=0;i<length;i++){
                arr[i]=p->data;
                p=p->father;
        }
        for(int i=length-1;i>=0;i--){
                printf("%d ",arr[i]);
        }

        system("pause");
        return 0;


}
/*
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
1 2 0 3 0 4 0 0 0
8 5 -100 5 8 0 0 0 0 0 0
-1 -2 -3 -4 0 0 0 0 0
*/
