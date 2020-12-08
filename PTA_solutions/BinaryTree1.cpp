/*
二叉树第k层最后一个结点

给定一棵非空二叉树，其结点的数据域为不等于0的整数，请编写程序输出该二叉树中第k层最后一个结点的值，
 若不存在则输出0。

输入格式:

输入第1行为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。其中空指针信息用0表示。第2行为一个整数k。

输出格式:

输出为一个整数，表示该二叉树中第k层最后一个结点的值，若不存在则输出0。

输入样例1:
1 2 0 0 3 0 0
1
输出样例1:
3


输入样例2:
1 -2 0 0 3 -1 0 0 -1 0 0
2
输出样例2:
-1

 */
/*
 * @Author: alone_yue
 * @Date: 2020-11-12 08:00:05
 */
#include<iostream>

#include<stdlib.h>
using namespace std;
class Node;

class AQueue{
//private:
public:
        int front;
        int rear;
        int count;//exist element number
        Node** QArray;
        int size;//arrray size数组规模
public:
        AQueue();
        int Count()const;//element number 两种不同的方式求
        bool IsEmpty()const;
        bool push(Node* item);
        bool pop();//出队列并赋值
        Node*& Back()const;//get tail not delete
        bool IsFull()const;
        Node*& Front()const;//get head not delete
};

class Node{
public:
        int data;
        Node* lChild;
        Node* rChild;
public:
        Node():lChild(nullptr),rChild(nullptr){}
};
class Btree{
//private:
public:
        Node* root;
        int size;
public:
        Btree();
        Node* pre_Creat();
        void layerOrder(AQueue A,int k,Node* proot);
};
Btree::Btree(){
        size=0;
        root=nullptr;
}
Node* Btree::pre_Creat(){
        int val; cin>>val;
        if(val==0)  return nullptr;
        this->size++;

        Node* current=new Node;
        current->data=val;
        current->lChild=pre_Creat();
        current->rChild=pre_Creat();
        return current;
}
void Btree::layerOrder(AQueue A,int k,Node* proot)//用到stl--queue
{
        if(proot!=nullptr){
                //AQueue A(1000);
                Node* t=proot; A.push(t);
                int cnt=0;
                while(!A.IsEmpty()){
                        int len=A.Count();
                        for(unsigned int i=0;i<len;i++){
                                Node* ptemp=A.Front(); A.pop();
                                if(ptemp->lChild!=nullptr) A.push(ptemp->lChild);
                                if(ptemp->rChild!=nullptr) A.push(ptemp->rChild);
                        }
                        cnt++;
                        if(cnt==k) break;
                }
                if(A.IsEmpty()) printf("0");
                else{
                        int data1=A.Back()->data;
                        printf("%d",data1);
                }
        }
}


Node*& AQueue::Front()const{
        return QArray[front];
}
AQueue::AQueue(){
        front=0;
        rear=0;
        count=0;
        size=1000;
        QArray=new Node*[size];
}
int AQueue::Count()const{
        //cout<<this->count<<endl;
        return (rear-front+size)%size;
}
bool AQueue::IsEmpty()const{
        if(this->rear==this->front&&count==0) return true;
        else return false;
}
bool AQueue::push(Node* item){
        this->QArray[this->rear]=item;
        rear=(rear+1)%size;
        count++;
        return true;
}
bool AQueue::pop(){
        front=(front+1)%size;
        count--;
        return true;
}
Node*& AQueue::Back()const{
        if(rear==0&&IsFull()) return QArray[rear+size-1];
        else if(rear==0&&!IsFull()) return QArray[rear+size-1];
        else if(rear!=0&&IsFull()) return QArray[rear];
        else return QArray[rear-1];
        //else if(rear!=0&&!IsFull()) return QArray[rear-1];

}
bool AQueue::IsFull()const{
        if(this->front==this->rear&&count==size) return true;
        else return false;
}


int main(){
        // AQueue C;
        // AQueue* A=&C;
        AQueue A;
        Btree B; B.root=B.pre_Creat();
        int k; scanf("%d",&k);
        B.layerOrder(A,k,B.root);

        system("pause");
        return 0;
}

