#include <bits/stdc++.h>

void bubble_sort(int arr[],int size);
void insert_sort(int arr[],int size);
void select_sort(int arr[],int size);
void swap(int& a,int &b);
int find_min(int arr[],int beg,int end);
int main()
{
        int arr[10]={1,78,5,23,98,256,234,1234,455,34};
        bubble_sort(arr,10);
        for(auto i:arr){ 
                std::cout << i<<" ";
        }
        std::cout<<std::endl;
        /*-----------------------------------------------------------*/
        int arr2[10]={1,78,5,23,98,256,234,1234,455,34};
        select_sort(arr2,10);
        for(auto i:arr2){ 
                std::cout << i<<" ";
        }
        std::cout<<std::endl;
        /*-----------------------------------------------------------*/
        int arr3[10]={1,78,5,23,98,256,234,1234,455,34};
        insert_sort(arr3,10);
        for(auto i:arr3){ 
                std::cout << i<<" ";
        }
        std::cout<<std::endl;
        /*-----------------------------------------------------------*/
        
}

void bubble_sort(int arr[],int size)
{
        bool sorted=false;
        while(!sorted){
                sorted=true;
                for(int i=1;i<size;i++){
                        if(arr[i-1]>arr[i]){
                                swap(arr[i-1],arr[i]);
                        }
                        sorted=false;
                }
                size--;
        }
}
void insert_sort(int arr[],int size)
{
        for(int i=1;i<size;i++){
                int tmp=arr[i];
                int j=i;
                while(j>0&&tmp<arr[j-1]){
                        arr[j]=arr[j-1];
                        j--;
                }
                arr[j]=tmp;
        }
}
void select_sort(int arr[],int size)
{
        int beg;
        int end=size;
        for(int i=0;i<size;i++){
                beg=i;
                int index=find_min(arr,beg,end);
                swap(arr[i],arr[index]);
        }
}

void swap(int& a,int &b)
{
        int tmp=a;
        a=b;
        b=tmp;
}
int find_min(int arr[],int beg,int end)
{
        int i;
        int min=__INT32_MAX__;
        int index=beg;
        for(i=beg;i<end;i++){
                if(arr[i]<min){
                        min=arr[i];
                        index=i;
                }
        }
        return index;
}