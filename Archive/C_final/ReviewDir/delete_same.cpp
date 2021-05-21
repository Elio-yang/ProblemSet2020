//
// Created by ELIO on 2020/12/29.
//

#include <cstdio>
int main()
{
        int arr[9]={-2,-1,-1,0,0,1,4,4,4};
        int size=9;
        int i=0;
        int j=1;
        int cnt=0;
        while (i<size&&j<size){
                if (arr[i]!=arr[j]){
                        i++;
                        arr[i]=arr[j];
                        j++;
                }else{
                        cnt++;
                        j++;
                }
        }
        printf("%d\n",cnt);
        for (int k = 0; k < size-cnt; k++) {
                printf("%d  ",arr[k]);
        }
        return 0;

}