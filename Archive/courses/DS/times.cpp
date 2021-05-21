#include <iostream>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[])
{
    int i,n,j,k;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int cnt4=0;
    n=1000;
    for (i=0;i<=n; i++){
            ++cnt1;
        for (j=0; j<=i; j++){
            ++cnt2;
            for(k=0;k<j;k++){
                ++cnt3;
            }
        }       
    }
    for(int m=0;m<=n;m++){
        cnt4+=(m*m+m);
    }
    int ans=cnt4/2;
    cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
    cout<<ans<<endl;
    system("pause");
    return 0;
}
