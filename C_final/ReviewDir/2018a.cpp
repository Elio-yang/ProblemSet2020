//
// Created by ELIO on 2020/12/30.
//
#include <stdio.h>
#include <limits.h>

double calc_s()
{
        double ans=0.0;
        double eps=1e-6;
        for(int n=1;;n++){
                int t=2*n/((2*n-1)*(2*n-1));
                ans+=t;
                if (t<eps){
                        break;
                }
        }
        return ans;
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

        if (*stra==*strb){
                return 0;
        }
        else if (*stra){
                return 1;
        }else if (*strb){
                return -1;
        }

}


void sort(char str[][10],int n)
{
        for (int i = 0; i < n; i++) {
                int beg=i;
                char *s=str[i];
                int index;
                for (int j = beg; j <n; j++) {
                        if (cmp(str[j],s)=-1){
                               s=str[j];
                               index=j;
                        }
                }
                char *tmp=str[i];
                str[i]=str[index];
                str[index]=tmp;
        }
}

int binary_search(int arr,int n,int key)
{
        if (n==1){
                return a[0]==key;
        }
        int mid=n/2;
        if (a[mid]==key){
                return 1;
        }else if (a[mid]>key){
                return binary_search(arr,mid,key);
        }else if (a[mid]<key){
                return binary_search(arr+mid+1,n-mid-1,key);
        }
}