/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/3/3
 */

#include <bits/stdc++.h>

long long mem[5010];

long long cnt_stairs(int n)
{
        if(n==1||n==0){
                return 1;
        }
        if(mem[n]==0){
                return mem[n]=cnt_stairs(n-1)+cnt_stairs(n-2);
        }
        return mem[n];
}

int main()
{
        int n;
        scanf("%d",&n);
        long long ans=cnt_stairs(n);
        printf("%lld",ans);
        return 0;
}