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
#include<iostream>
#include<cstdlib>

using namespace std;
class node {
public:
        int data;
        node *lChild;
        node *rChild;

        node() : lChild(nullptr), rChild(nullptr)
        {}
};
class accumulate_queue {
public:
        int front;
        int rear;
        int count;//exist element number
        node **QArray;
        int size;//arrray size数组规模

        accumulate_queue()
        {
                front = 0;
                rear = 0;
                count = 0;
                size = 1000;
                QArray = new node *[size];
        }
        int Count() const//element number 两种不同的方式求
        {
                return (rear - front + size) % size;
        }

        bool IsEmpty() const
        {
                if (this->rear == this->front && count == 0) return true;
                else return false;
        }


        bool push(node *item)
        {
                this->QArray[this->rear] = item;
                rear = (rear + 1) % size;
                count++;
                return true;
        }

        bool pop()//出队列并赋值
        {
                front = (front + 1) % size;
                count--;
                return true;
        }
        node *&Back() const//get tail not delete
        {
                if (rear == 0 && IsFull()) return QArray[rear + size - 1];
                else if (rear == 0 && !IsFull()) return QArray[rear + size - 1];
                else if (rear != 0 && IsFull()) return QArray[rear];
                else return QArray[rear - 1];
                //else if(rear!=0&&!IsFull()) return QArray[rear-1];

        }
        bool IsFull() const
        {
                if (this->front == this->rear && count == size) return true;
                else return false;
        }
        node *&Front() const//get head not delete
        {
                return QArray[front];
        }
};
class Tree {
public:
        node *root;
        int size;
        Tree()
        {
                size = 0;
                root = nullptr;
        }

        node *pre_Creat()
        {
                /*前序创建树*/
                int val;
                cin >> val;
                if (val == 0) return nullptr;
                this->size++;

                node *current = new node;
                current->data = val;
                current->lChild = pre_Creat();
                current->rChild = pre_Creat();
                return current;
        }

        void layerOrder(accumulate_queue A, int k, node *proot)
        {
                if (proot != nullptr) {
                        //AQueue A(1000);
                        node *t = proot;
                        A.push(t);
                        int cnt = 0;
                        while (!A.IsEmpty()) {
                                int len = A.Count();
                                for (unsigned int i = 0; i < len; i++) {
                                        node *ptemp = A.Front();
                                        A.pop();
                                        if (ptemp->lChild != nullptr) A.push(ptemp->lChild);
                                        if (ptemp->rChild != nullptr) A.push(ptemp->rChild);
                                }
                                cnt++;
                                if (cnt == k) break;
                        }
                        if (A.IsEmpty()) printf("0");
                        else {
                                int data1 = A.Back()->data;
                                printf("%d", data1);
                        }
                }
        }

};

int main()
{
        accumulate_queue A;
        Tree B;
        B.root = B.pre_Creat();
        int k;
        scanf("%d", &k);
        B.layerOrder(A, k, B.root);
        return 0;
}

