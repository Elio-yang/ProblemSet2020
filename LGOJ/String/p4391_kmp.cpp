#include<cstdio>
#include<cstring>
#include<cstdlib>

/*
cab cab cab cab ca
    cab cab cab ca b ca
ans = len - (fail[len-1]+1)
index from 0 to len-1
*/

int *build_fail(const char *P);

int main()
{
        int n;
        scanf("%d",&n);
        char str[1000010];
        scanf("%s",str);
        int len=strlen(str);
        int *f=build_fail(str);
        int ans=len-(f[len-1]+1);
        printf("%d",ans);
        //system("pause");
        return 0;
}
int *build_fail(const char *P)
{
        int m=strlen(P);
        int *F=(int*)malloc(sizeof(int)*m);
        F[0]=-1;
        for(int j=1;j<m;j++){
                int i=F[j-1];
                while(P[j]!=P[i+1]&&i>=0){
                        i=F[i];
                }
                if(P[j]==P[i+1]){
                        F[j]=i+1;
                }
                else{
                        F[j]=-1;
                }
        }
        return F;
}