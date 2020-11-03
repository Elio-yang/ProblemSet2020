#include <cstdio>
#include <cstring>
/*f[i]=f[i-1]+f[i-2]*/
long long int mem[55];
long long int fibo(int m);
int main()
{
        int n;
        while(~scanf("%d",&n)){
                while(n--){
                        int a,b;
                        scanf("%d %d",&a,&b);
                        long long int n=fibo(b-a);
                        printf("%lld\n",n);
                }
        }
        return 0;
}
long long int fibo(int m)
{
        if(m<=1){
                return 1;
        }
        if(mem[m]==0){
                mem[m]=fibo(m-1)+fibo(m-2);
        }
        return mem[m];
}