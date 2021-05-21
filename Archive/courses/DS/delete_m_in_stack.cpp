#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;
stack<int> Src;
stack<int> Tmp;
void delete_m(int m)
{
    while(!Src.empty()){
        int tmp=Src.top();
        if(tmp!=m){
            Tmp.push(tmp);
        }
        Src.pop();
    }
    while(!Tmp.empty()){
        Src.push(Tmp.top());
        Tmp.pop();
    }
}
template<typename T>
void display_stack(stack<T> s)
{
    int cnt=0;
    while(!s.empty()){
        T tmp=s.top();
        s.pop();
        cout<<(int)tmp<<" ";
        if(cnt++%10==9){
            cout<<endl;
        }
    }
}
int main()
{
    int m=10;
    for(int i=0;i<100;i++){
        (i%10==9)?(Src.push(m)):(Src.push(i));
    }
    cout<<"before delete m=10: "<<endl;
    display_stack(Src);
    cout<<"after delete m=10: "<<endl;
    delete_m(m);
    display_stack(Src);
    cout<<endl;
    system("pause");
}

