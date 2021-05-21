//
// Created by ELIO on 2020/12/30.
//

#include <stdio.h>
#include <limits.h>
void selection_sort(int arr[],int n)
{
        for (int i = 0; i <n ; i++) {
                int beg;
                int max=INT_MIN;
                int index;
                for(beg=i;beg<n;beg++){
                        if (arr[beg]>max){
                                max=arr[beg];
                                index=beg;
                        }
                }
                int tmp=arr[i];
                arr[i]=arr[index];
                arr[index]=tmp;
        }
}

char* max_len(char *str[],int n){
        int max_len=INT_MIN;
        int index;
        int i;
        for ( i = 0; i < n; i++) {
                int j=0;
                int len=0;
                char *s=str[i];
                while (*s){
                        len++;
                        s++;
                }
                if (len>max_len){
                        max_len=len;
                        index=i;
                }
        }
        return str[i];
}

float fn(int n,float x)
{
        if (n==1){
                return 1;
        }else if(n==2){
                return x;
        }else{
                return 2*fn(n-2,x-2)+3*fn(n-1,x-1);
        }
}



