#include<iostream>
#include<cstdlib>

using namespace std;
int main()
{
    // int ans1=0;
    // int ans2=0;
    // for(int i=1;i<=2015;i++){
    //     ans1+=(2015/i);
    //     cout<<i<<":"<<2015/i<<" ";
    //     if(i%10==0){
    //         cout<<endl;
    //     }
    // }
    // cout<<endl;
    // for(int i=1;i<=2014;i++){
    //     ans2+=(2014/i);
    //     cout<<i<<":"<<2014/i<<" ";
    //     if(i%10==0){
    //         cout<<endl;
    //     }
    // }
    for(int i=1;i<=2015;i++){
        int res=(int)2015/i - (int)2014/i;
        if(res!=0){
            cout<<i<<":   "<<res<<"   ";
        }
        // if(i%10==0){
        //     cout<<endl;
        // }
    }
    // cout<<ans1-ans2<<endl;

    system("pause");
    return 0;
}