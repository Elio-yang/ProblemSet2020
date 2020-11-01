#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int mem[45];

int stair(int n);
int main()
{
        int m;
        while(~scanf("%d",&m)){
                for(int i=0;i<m;i++){
                        int n;
                        scanf("%d",&n);
                        printf("%d\n",stair(n));
                }
        }
        return 0;
}

int stair(int n){
        if(n<=2){
                return 1;
        }
        if(mem[n]==0){
                mem[n]=stair(n-1)+stair(n-2);
        }
        return mem[n];
}