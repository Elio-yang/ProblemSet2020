/*
 ## 树和等于某值路径 (10分)

已知树结点为不等于0的整数。给定一个整数K，请编写程序找出以根结点为起点叶结点为终点的所有路径中，结点值之和等于K的路径，如果多条路径满足条件，则输出最左边一条。例如K=15，对于图1(a)所示的树t，满足条件的路径为8-5-2、8-3-4和8-7，应输出最左边一条为8-5-2。若没有满足条件的路径，则亦能识别。

![tree.jpg](https://images.ptausercontent.com/73853096-0374-47f1-8c6c-f4db51d40ceb.jpg)

### 输入格式:

输入为2行，第一行为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。其中空指针信息用0表示。第2行为整数K。

注：我们已知二叉树与其自然对应的树相比，二叉树中结点的左孩子对应树中结点的左孩子，二叉树中结点的右孩子对应树中结点的右兄弟。进而我们可以利用“基于引入空指针信息的先根序列构建二叉树”的方法来构建其对应的树的左孩子-右兄弟存储结构。如1 2 0 3 0 4 0 0 0对应如图1(b)所示的树。

### 输出格式:

输出为一行整数，每个整数后一个空格，即所求路径包含的结点值（按从根到叶的顺序），如果存在多条满足条件路径，则输出最左边一条。若没有满足条件的路径，则输出0，后面无空格。

### 输入样例1:

```in
1 2 0 3 0 4 0 0 0
5
```

### 输出样例1:

```out
1 4
```

### 输入样例2:

```in
1 2 0 0 3 0 0
9
```

### 输出样例2:

```out
0
```

*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class node;
node* Count[1000];
int cnt=0;

class node{
public:
        int data;
        int sum;
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
        node* pre_Creat(node* p, int sum);
        void tran(int k, node* proot);
};
node* Tree::pre_Creat(node* p, int sum){
        int val; scanf("%d",&val);
        if(val==0) return nullptr;

        node* cur=new node;
        cur->data=val;
        cur->sum=sum+cur->data;
        cur->father=p;
        cur->lChild=pre_Creat(cur,cur->sum);
        if(p!=nullptr)  cur->rbro=pre_Creat(cur->father,cur->father->sum);
        else cur->rbro=pre_Creat(cur->father,0);
        return cur;
}
void Tree::tran(int k, node* proot){
        if(proot->lChild==nullptr&&proot->rbro==nullptr){
                if(proot->sum==k){
                        arr[cnt++]=proot; return ;
                }
        }
        if(proot->lChild!=nullptr){
                tran(k,proot->lChild);
        }
        if(proot->rbro!=nullptr){
                tran(k,proot->rbro);
        }

}
int main(){
        Tree T;
        T.root=T.pre_Creat(nullptr,0);
        int k; cin>>k;
        T.tran(k,T.root);
        if(cnt==0) cout<<0<<endl;
        else{
                int arr1[100]; int cnt1=0;
                node* p=arr[0];
                while(p!=nullptr){
                        arr1[cnt1++]=p->data;
                        p=p->father;
                }

                for(int i=cnt1-1;i>=0;i--){
                        cout<<arr1[i]<<" ";
                }

        }

        system("pause");
        return 0;


}