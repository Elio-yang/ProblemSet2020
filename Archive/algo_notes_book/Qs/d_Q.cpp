#include<bits/stdc++.h>
using namespace std;
int main()
{
        int bits[40];
        int cnt=0;
        int num;
        int Q;
        cin>>num>>Q;
        do{
                bits[cnt++]=num%Q;
                num/=Q;
        }while(num!=0);
        for(int i=cnt-1;i>=0;i--){
                cout<<bits[i];
        }
        cout<<endl;
        return 0;
}