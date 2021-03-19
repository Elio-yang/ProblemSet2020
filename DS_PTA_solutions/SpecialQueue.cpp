/*
 D 特殊队列 (10分)

给定一个特殊的队列，支持如下操作：

ENQUEUE X：入队一个整数X；

DEQUEUE：出队一个元素；

REVERSE：对队列的每个元素取反，即X变为-X；

MAXIMUM：取队列中值最大的元素，若队列为空则忽略该操作。

输入格式:

第一行为正整数T，表示测试数据的组数。对于每组测试数据，第一行为一个正整数n，
 表示操作的个数，接下来n行，每行表示一个操作。T不超过10，n不超过2000000。

输出格式:

对于每一个未被忽略的MAXIMUM操作，输出该操作的返回值。每组测试数据的结果间隔一个空行。

输入样例:

1
6
ENQUEUE -8
REVERSE
ENQUEUE -5
MAXIMUM
DEQUEUE
MAXIMUM


输出样例:
8
-5
 */
/*
 * @Author: alone_yue
 * @Date: 2020-10-29 16:12:57
 */
#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

class Astack{
public:
        int size;
        int* stackArray;
        int top;
        int tail;
public:
        Astack(int n);
        void Push(int item);
        void Pop();
        int intop();
        int intail();

};
Astack::Astack(int n){
        size=n;
        stackArray=new int[size];
        top=-1;
        tail=0;
}
void Astack::Push(int item){
        stackArray[++top]=item;
}
void Astack::Pop(){
        top--;
}
int Astack::intop(){
        return stackArray[top];
}
int Astack::intail(){
        return stackArray[tail];
}

int main(){
        // queue<int> q1;
        // Astack q1max(2000001);
        // queue<int> q2;
        // Astack q2max(2000001);

        // bool rev=true;//默认没取反

        int group; scanf("%d",&group);
        for(int i=0;i<group;i++){

                queue<int> q1;
                Astack q1max(2000001);
                queue<int> q2;
                Astack q2max(2000001);

                bool rev=true;//默认没取反

                int amount; scanf("%d",&amount);
                for(int j=0;j<amount;j++){
                        char c[8]; scanf("%s",c);

                        if(c[0]=='E'){
                                int a; scanf("%d",&a);
                                if(rev==true){
                                        q1.push(a); q2.push(-a);
                                        if(q1max.top<q1max.tail||a<=q1max.intop()) q1max.Push(a);
                                        else{
                                                while(q1max.top>=q1max.tail&&a>q1max.intop()){q1max.Pop();}
                                                q1max.Push(a);
                                        }
                                        if(q2max.top<q2max.tail||-a<=q2max.intop()) q2max.Push(-a);
                                        else{
                                                while(q2max.top>=q2max.tail&&-a>q2max.intop()){q2max.Pop();}
                                                q2max.Push(-a);
                                        }
                                }
                                if(rev==false){
                                        q1.push(-a); q2.push(a);
                                        if(q1max.top<q1max.tail||-a<=q1max.intop()) q1max.Push(-a);
                                        else{
                                                while(q1max.top>=q1max.tail&&-a>q1max.intop()){q1max.Pop();}
                                                q1max.Push(-a);
                                        }
                                        if(q2max.top<q2max.tail||a<=q2max.intop()) q2max.Push(a);
                                        else{
                                                while(q2max.top>=q2max.tail&&a>q2max.intop()){q2max.Pop();}
                                                q2max.Push(a);
                                        }
                                }
                        }

                        if(c[0]=='D'&&q2max.top>=q2max.tail&&q1max.top>=q1max.tail&&!q1.empty()&&!q2.empty()){

                                if(q1.front()>=q1max.intail()) {q1.pop(); q1max.tail++;}
                                else q1.pop();
                                if(q2.front()>=q2max.intail()) {q2.pop(); q2max.tail++;}
                                else q2.pop();

                        }

                        if(c[0]=='R') rev=!rev;
                        if(c[0]=='M'){
                                if(rev==true&&q1max.top>=q1max.tail) printf("%d\n",q1max.intail());
                                if(rev==false&&q2max.top>=q2max.tail) printf("%d\n",q2max.intail());

                        }
                }
                if(i!=group-1) printf("\n");
        }
        system("pause");
        return 0;
}
