//
// Created by ELIO on 2020/12/30.
//
#include <limits.h>
#include <stdio.h>

void sort_del(int arr[],int n,int j)
{
        for (int i = 0; i < n; i++) {
                int index;
                int min=INT_MAX;
                int beg=i;
                for (int k = beg; k <n ; k++) {
                        if (arr[k]<min){
                                min=arr[k];
                                index=k;
                        }
                }

                int tmp=arr[i];
                arr[i]=arr[index];
                arr[index]=tmp;
        }
        for (int i = j; i <n ; i++) {
                arr[i-j]=arr[i];
        }
}

int cmp(char *stra,char *strb)
{
        while (*stra&&*strb){
                if (*stra>*strb){
                        return 1;
                }else if(*stra<*strb){
                        return -1;
                }
                stra++;
                strb++;
        }

        if (*stra=='\0'&&*strb=='\0'){
                return 0;
        }else if(*stra){
                return 1;
        }else if(*strb){
                return -1;
        }
}

char *final(char* str[],int n)
{
        char *max_str=str[0];
        int i;
        int index;
        for ( i = 0; i < n; i++) {
                if (cmp(max_str,str[i])==1){
                        max_str=str[i];
                        index=i;
                }
        }
        return str[index];
}

