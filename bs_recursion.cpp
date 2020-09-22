#include<iostream>
#include<cstdlib>


using namespace std;

int find_max(int arr[],int beg,int end);

int main(int argc, char *argv[])
{
    int arr[4]={1,2,3,4};
    int max=find_max(arr,0,3);
    cout<<max<<endl;
    system("pause");
    return 0;
}

int find_max(int arr[],int beg,int end)
{
    if(beg==end){
        return arr[beg];
    }else{
        int mid=(beg+end)/2;
        int tmp1=find_max(arr,beg,mid);
        int tmp2=find_max(arr,mid+1,end);
        if(tmp1>tmp2){
            return tmp1;
        }else{
            return tmp2;
        }
    }
}
