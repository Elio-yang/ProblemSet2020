//
// Created by ELIO on 2020/12/6.
//
/*队列ADT*/
#include <cstdio>
const int maxn = 10000;

template<typename T>class queue{
        static constexpr int Empty=-1;
        int size;
        int Front;
        int Rear;
        T *arr;
public:
        queue<T>():Front(1),Rear(0),size(0){
                arr=new T[maxn];
        }

        void pop(){
                ++Front;
                --size;
        }
        void push(T e){
                arr[++Rear]=e;
                ++size;
        }
        T& front(){
                return arr[Front];
        }
        bool empty(){
                return size==0;
        }
        ~queue<T>(){
                delete []arr;
        }
};

int main()
{
        queue<int> Q;
        for (int i = 0; i < 100; i++) {
                Q.push(i);
        }
        while (!Q.empty()){
                printf("%d ",Q.front());
                Q.pop();
        }
        return 0;
}