#include <cstdio>

int binary_search(int arr[],int len,int target)
{
        int low=0;
        int hi=len-1;
        while (low<=hi){
                int mid=(hi+low)/2;
                if (arr[mid]==target){
                        return mid;
                }
                else if(arr[mid]<target){
                        low=mid+1;
                }
                else if(arr[mid]>target){
                        hi=mid-1;
                }
        }
        return -1;
}

int binary_search_r(int arr[],int len,int target)
{
        if (len==1){
                return arr[0]==target;
        }
        int mid=len/2;
        if (arr[mid]==target){
                return 1;
        }
        else if (arr[mid]<target){
                return binary_search_r(arr+mid+1,len-mid-1,target);
        }
        else{
                return binary_search_r(arr,mid,target);
        }

}

int main()
{
        int arr[]={-387,-9,-5,-4,-4,-4,-4,-3,-2,-1,0,0,0,0,8,24,77,87,92,455,2332,23456};
        int len=sizeof(arr)/sizeof(arr[0]);
        int target=0;
        int index=binary_search(arr,len,target);
        printf("%d",index);
        return 0;
}
