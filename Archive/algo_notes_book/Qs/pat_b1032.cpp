#include<bits/stdc++.h>
using namespace std;
int main()
{
        long  N;
        int id;
        int credit;
        int index=0;
        int max=0;
        cin>>N;
        long socre[N]={};
        while(cin>>id>>credit){
                socre[id-1]+=credit;
        }
        for(int i=0;i<N;i++){
                if(socre[i]>max){
                        max=socre[i];
                        index=i;
                }
        }
        cout<<index+1<<" "<<max<<endl;
        return 0;
}