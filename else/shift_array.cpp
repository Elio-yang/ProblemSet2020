/*
 1 2 3 4 5
 shift by two
 3 4 5 1 2
*/
#include <iostream>
#include <cstdlib>
 
using namespace std;

void shift_by_k(int arr[] ,int k, int len);
void swap_arr(int *a,int *b);
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    shift_by_k(arr,2,sizeof(arr)/sizeof(arr[0]));
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}
void shift_by_k(int arr[] ,int k, int len)
{
    /*1 2 3 4 5
      2 1 3 4 5*/
    for(int i=0;i<k;i++){
        swap_arr(&arr[i],&arr[k-1-i]);
    }
    /*2 1 3 4 5
      2 1 5 4 3*/
    for(int i=k;i<(len-1+k)/2;i++){
        swap_arr(&arr[i],&arr[len-1-(i-k)]);
    }
    /*2 1 5 4 3
      3 4 5 1 2*/
    for(int i=0;i<len/2;i++){
        swap_arr(&arr[i],&arr[len-1-i]);
    }
}
void swap_arr(int* a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}