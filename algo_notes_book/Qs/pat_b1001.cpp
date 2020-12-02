#include <bits/stdc++.h>
using namespace std;
int main()
{
        unsigned cnt=0;
        unsigned n;
        cin>>n;
        
        while(n!=1){
                if(n%2==0){
                        n/=2;
                        cnt++;
                }else{
                        n=(3*n+1)/2;
                        cnt++;
                }
        }
        cout<<cnt<<endl;
        return 0;
}