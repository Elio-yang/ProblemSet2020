#include<iostream>
#include<cstdlib>

using namespace std;


void move(char a,char b);
void solve(int n,char a,char b,char c);
static int cnt=0;

int main(int argc, char const *argv[])
{
    solve(7,'a','b','c');
    cout<<cnt<<endl;
    system("pause");
    return 0;
}

void move(char a,char b)
{
    cout<<a<<"--->"<<b<<endl;
    ++cnt;
}
void solve(int n,char a,char b,char c)
{
    if(n==0){
        return ;
    }
    solve(n-1,a,c,b);
    move(a,b);
    solve(n-1,c,a,b);
    
}