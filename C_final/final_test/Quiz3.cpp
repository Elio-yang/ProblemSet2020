#include <stdio.h>

int f(int m,int n)
{
        if (m<=0||n<=0||m<n){return -1;}
        else if (m==n){return 1;}
        else if (n==1){return m;}
        else{
                return f(m-1,n)+f(m-1,n-1);
        }
}

int main()
{
        int m,n;
        scanf("%d %d",&m,&n);
        int ans=f(m,n);
        printf("%d",ans);
        return 0;
}