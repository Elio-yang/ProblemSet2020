#include <iostream>
using namespace std;

template<typename T>
class stack{
private:
        static constexpr int Empty=-1;
        int size;
        int Low;
        int Top;
        T *arr;
        int max_size;
public:
        explicit stack<T>(int n):Top(Empty),max_size(n),Low(0),size(0){
                arr =new T[n];
                if (arr== nullptr){
                        cerr<<"heap overflow"<<endl;
                        return;
                }
        }
        int empty(){
                return (Top==Empty||size==0);
        }
        void push(T d){
                if(Top==max_size-1){
                        cerr<<"stack full error"<<endl;
                        return ;
                }
                arr[++Top]=d;
                ++size;
        }
        void pop(){
                if(empty()){
                        cerr<<"stack empty error"<<endl;
                        return;
                }
                --Top;
                --size;

        }
        T top(){
                return arr[Top];
        }
};

/*test*/
int main()
{
        stack<int> s(1000);
        for (int i = 0; i < 5; i++) {
                s.push(i);
        }
        while (!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
        }
        cout<<endl;

        s.pop();

        return 0;
}