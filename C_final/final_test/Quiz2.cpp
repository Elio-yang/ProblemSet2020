#include <stdio.h>
#include <string.h>

int main()
{
        char in[100];
        int f=1;
        scanf("%s",in);
        int len=strlen(in);
        for (int i = 0; i <= len-2; i++) {
                if(in[i]-in[i+1]>=0){
                        continue;
                }else{
                        f=0;
                        break;
                }
        }

        if (f==0){
                printf("NO");
        }else{
                printf("YES");
        }
        return 0;
}