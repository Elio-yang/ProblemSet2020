#include <cstdio>

int main()
{
        char str[110];
        while(scanf("%s",str)!=EOF){
                char max=str[0];
                for(int i=1;str[i]!='\0';i++){
                        if(str[i]>max){
                                max=str[i];
                        }
                }
                for(int i=0;str[i]!='\0';i++){
                        if(str[i]==max){
                                printf("%c(max)",str[i]);
                        }else{
                                printf("%c",str[i]);
                        }
                }
                printf("\n");
        }
}