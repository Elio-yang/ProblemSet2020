#include <stdio.h>
#include <stdlib.h>

#define maxn 110

int main()
{
        int cnt=0;
        bool input[maxn]={0};
        int all=0;
        scanf("%d",&all);
        for(int i=0;i<all;i++){
                scanf("%d",&input[i]);
        }
        for(int i=0;i<all;i++){
                if(cnt<0){
                        printf("0");
                        break;
                }
                if(input[i]==1){
                        cnt++;
                }
                else if(input[i]==0){
                        cnt--;
                }
        }
        if(cnt==0){
                printf("1");
        }
        else if(cnt>0){
                printf("0");
        }
        system("pause");
        return 0;
}