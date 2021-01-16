//
// Created by ELIO on 2020/12/29.
//

#include <stdio.h>
#include <limits.h>

void mid_num(int a[],int cnt,int k)
{
        int min=INT_MAX;
        int index=0;
        for (int i = 0; i < cnt; i++) {
                if (a[i]<min){
                        min=a[i];
                        index=i;
                }
        }
        int tmp=a[0];
        a[0]=a[index];
        a[index]=tmp;

        if (k==1){
                printf("mid position num is %d",a[0]);
                return;
        }
        mid_num(a+1,cnt-1,k-1);
}


int prod(char a[])
{
        if ('0'<=a[0]&&a[0]<='9'){
                return (a[0]-'0')*prod(a+1);
        }
        else if (a[0]!='\0'){
                return 1*prod(a+1);
        }
        else{
                return 1;
        }
}


int main()
{
        int arr[]={-400,-387,-9,-5,-4,-4,-4,-4,-3,-2,-1,0,0,0,0,8,24,77,87,92,455,2332,23456};
        mid_num(arr,sizeof(arr)/ sizeof(arr[0]), sizeof(arr)/ sizeof(arr[0])/2);
        printf("\n");
        char str[]="12ab3 3v7";
        printf("%d",prod(str));

        return 0;
}