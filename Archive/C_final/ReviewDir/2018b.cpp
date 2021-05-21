//
// Created by ELIO on 2020/12/30.
//

int binary_search(int a[],int n,int k)
{
        int low=0;
        int hi=n-1;
        int mid=0;
        while (low<=hi){
                mid=(hi+low)/2;
                if (a[mid]==k){
                        return 1;
                }else if (a[mid]>k){
                        hi=mid-1;
                }else if (a[mid]<k){
                        low=mid+1;
                }
        }
        return -1;
}

#define N 10
int judge(int arr[N][N],int i,int j)
{
        int ele=arr[i][j];
        int max=-999;
        for (int k = 0; k <N; k++) {
                if (arr[i][k]>max){
                        max=arr[i][k];
                }
        }
        int num=0;
        for (int k = 0; k < N; k++) {
                if (ele>arr[k][j]){
                        num++;
                }
        }

        return (num==j/2)&&(max==ele);
}

void ops_arr(int arr[N][N])
{
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (judge(arr,i.j)){
                                printf("%d",arr[i][j]);
                        }
                }
        }
}