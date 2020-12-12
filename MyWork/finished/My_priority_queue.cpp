/*
 * priority_queue<T> q
 * 实现小顶堆
 * 支持操作：
 *      1.创建
 *      2.插入
 *      3.删除最小值
 *      4.取顶
 **/

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxsize=10000;

/*
 * T 需要重载比较运算符来实现优先级
 * bool operator<(const T& b)const{return ??}
 * bool operator>(const T& b)const{return ??}
 **/

template<typename T>
class priority_queue{
private:
        //当前的大小
        int size;
        //最大的规模
        int Capcity;
        //堆的存放
        T* eles;
public:
        //无参构造函数
        priority_queue<T>():size(0),Capcity(maxsize){
                eles=new T[maxsize+1];
        }
        void push(T E);
        T top();
        void pop();
        bool empty();
};

template<typename T>
void priority_queue<T>::push(T E)
{
        int i;
        for(i=++size;eles[i/2]> E;i>>=1){
                eles[i]=eles[i>>1];
        }
        eles[i]=E;
}

template<typename T>
T priority_queue<T>::top()
{
        return eles[1];
}

template<typename T>
void priority_queue<T>::pop()
{
        int i,child;
        T last_ele=eles[size--];
        for(i=1;2*i<=size;i=child){
                child=i<<1;
                if (child!=size&&eles[child+1]<eles[child]){
                        child++;
                }
                if (last_ele>eles[child]){eles[i]=eles[child];}
                else break;
        }
        eles[i]=last_ele;
}
template<typename T>
bool priority_queue<T>::empty()
{
        return size==0;
}

struct node{
        int v;
        int w;
        /*记得每次要重载这俩比较运算符*/
        bool operator<(const node& b)const{
                return w<b.w;
        }
        bool operator>(const node& b)const{
                return w>b.w;
        }
};



int main()
{
        node arr[]={{1,86},
                    {2,438467},
                    {3,63478264},
                    {4,2367856},
                    {5,22334},
                    {6,123},
                    {7,1},
                    {8,3},
                    {9,6},
                    {10,7}};
        priority_queue<node> q;
        for (auto i : arr) {
                q.push(i);
        }
        while (!q.empty()){
                node min=q.top();
                q.pop();
                printf("{v=%d w=%d} ",min.v,min.w);
        }
        return 0;
}




