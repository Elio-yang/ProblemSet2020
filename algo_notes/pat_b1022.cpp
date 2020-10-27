#include <bits/stdc++.h>
using namespace std;
int  main()
{
        long A,B,D;
        cin>>A>>B>>D;
        long result=A+B;
        int bits[40];
        int cnt=0;
        do{
                bits[cnt++]=result%D;
                result/=D;
        }while(result!=0);
        for(int i=cnt-1;i>=0;i--){
                cout<<bits[i];
        }
        cout<<endl;
        return 0;
}