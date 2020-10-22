#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    char *s=(char*)malloc(sizeof(char)*(n+1));
    scanf("%s",s);
    int len=n;
    char *str=(char*)malloc(sizeof(char)*(len+1));
    int i,j;
    for(i=0,j=0;i<=len/2;i++){
        if(i<len/2){
            str[j]=s[2*i];
            j++;
        }
        str[len/2+i]=s[2*i+1];
    }
    str[len]='\0';
    int k;
    if(len%2==0){
        k=len/2+len/4-1;
    }else{
        k=len/2+len/4;
    }
    for(int i=len/2,j=0;i<=k;i++){
        char tmp=str[i];
        str[i]=str[len-1-j];
        str[len-1-j]=tmp;
        j++;
    }
    printf("%s",str);
    system("pause");
    return 0;
}