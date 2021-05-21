#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n){
                if(!(n>=1&&n<=30)){
                        continue;
                }
                int dp[n][n];
                memset(dp,0,sizeof(int)*n*n);

                for(int i=0;i<n;i++){
                        dp[i][i]=dp[i][0]=1;
                        for(int j=1;j<i;j++){
                                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                        }
                }
                for(int i=0;i<n;i++){
                        for(int j=0;j<=i;j++){
                                if(j==i){
                                printf("%d",dp[i][i]);
                                }else{
                                printf("%d ",dp[i][j]);
                                }
                        }
                        printf("\n");
                }
                printf("\n");
        }
        

        return 0;
}