/*
 已知二叉树结点为不等于0的整数。给定一个整数K，
 请编写程序找出以根结点为起点叶结点为终点的所有路径中，结点值之和等于K的所有路径。
 例如K=15，对于下图所示的二叉树t，满足条件的路径有2条，即8-5-2和8-7。
 若没有满足条件的路径，则亦能识别。

![img.jpg](https://images.ptausercontent.com/f1bd43b7-796e-47ae-a9f5-8ffc0300858b.jpg)

输入格式:

输入为2行，第一行为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列，其中空指针信息用0表示。第2行为整数K。

输出格式:

输出第一行为一个整数，表示满足条件的路径条数；若没有满足条件的路径，则输出0。从第二行开始，每行为一条满足条件的路径，若有多条满足条件的路径，则按从左到右的顺序依次输出，路径中每个结点值后一个空格，若两条不同的路径包含的各结点值恰好相等，则都需输出。

输入样例1:
8 5 1 0 0 2 0 0 7 0 0
15
输出样例1:
2
8 5 2
8 7

输入样例2:
-1 2 0 0 3 0 0
2
输出样例2:
1
-1 3

输入样例3:
1 1 0 0 1 0 0
2
输出样例3:
2
1 1
1 1

输入样例4:
-1 2 0 0 3 0 0
8
输出样例4:
0
 */
/*
 * @Author: alone_yue
 * @Date: 2020-11-12 07:59:57
 */
#include<iostream>
#include<stdlib.h>
using namespace std;
class Node;
Node* arr[1000];
int cnt=0;

class Node{
public:
        int data;
        int sum;
        Node* lChild;
        Node* rChild;
        Node* father;
public:
        Node():lChild(nullptr),rChild(nullptr),father(nullptr){}
};
class Btree{
//private:
public:
        Node* root;
        int size;
public:
        Btree();
        Node* pre_Creat(Node* father,Node* proot,int sum);
        void tran(int k,Node* proot);

};
Btree::Btree(){
        size=0;
        root=nullptr;
}
Node* Btree::pre_Creat(Node* father,Node* proot,int sum){
        proot=new Node;
        Node* father_node=father;
        Node* proot_node=proot;
        int val; scanf("%d",&val);
        if(val==0)  return nullptr;

        proot_node->data=val; proot_node->sum=sum+proot_node->data;
        proot_node->father=father_node;
        proot_node->lChild=pre_Creat(proot_node,proot_node->lChild,proot_node->sum);
        proot_node->rChild=pre_Creat(proot_node,proot_node->rChild,proot_node->sum);
        return proot_node;
}
void Btree::tran(int k,Node* proot){
        if(proot->lChild==nullptr&&proot->rChild==nullptr){
                if(proot->sum==k){
                        arr[cnt++]=proot; return ;
                }
        }
        if(proot->lChild!=nullptr){
                tran(k,proot->lChild);
        }
        if(proot->rChild!=nullptr){
                tran(k,proot->rChild);
        }

}


int main(){
        Btree B;
        B.root=B.pre_Creat(nullptr,B.root,0);
        int k; scanf("%d",&k);
        B.tran(k,B.root);
        printf("%d\n",cnt);



        for(int i=0;i<cnt;i++){
                int arr1[100]={0}; int w=0;
                arr1[w++]=arr[i]->data;
                Node* www=arr[i];
                int par=arr[i]->data;
                while(1){
                        Node* par1=www->father;
                        if(par1!=nullptr)
                        {arr1[w++]=par1->data;
                                www=par1;}
                        if(par1==nullptr) break;
                }
                int am;
                for(int j=0;;j++){
                        if(arr1[j]==0){
                                am=j; break;
                        }
                }
                for(int j=am-1;j>=0;j--){
                        printf("%d ",arr1[j]);
                }
                printf("\n");
        }

        system("pause");
        return 0;




}
