#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;
void transfer(long num,int Q);
stack<int> digit;

int main()
{
    char *arr=static_cast<char*>("1024");
    // int Q;
    // scanf("%s",arr);
    long num=strtol(arr,NULL,10);
    // scanf("%d",&Q);
    transfer(num,2);
    while(!digit.empty()){
        cout<<digit.top();
        digit.pop();
    }
    return 0;
}
void transfer(long num,int Q)
{
    do{
        digit.push(num%Q);
        num/=Q;
    }while(num!=0);
}
