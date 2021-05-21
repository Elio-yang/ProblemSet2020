#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void merge(int A[],int tmp[],int l_pos,int r_pos,int r_end)
{
        int l_end,cnt,p_tmp;
        l_end=r_pos-1;
        p_tmp=l_pos;
        cnt=r_end-l_pos+1;
        while (l_pos<=l_end&&r_pos<=r_end){
                if(A[l_pos]<=A[r_pos]){
                        tmp[p_tmp++]=A[l_pos++];
                }else{
                        tmp[p_tmp++]=A[r_pos++];
                }
        }
        while (l_pos<=l_end){
                tmp[p_tmp++]=A[l_pos++];
        }
        while (r_pos<=r_end){
                tmp[p_tmp++]=A[r_pos++];
        }
        for (int i = 0; i < cnt; i++,r_end--) {
                A[r_end]=tmp[r_end];
        }
}

void divide(int *A, int *tmp, int left, int right)
{
        if(left<right){
                int mid=(left+right)/2;
                divide(A, tmp, left, mid);
                divide(A, tmp, mid + 1, right);
                merge(A,tmp,left,mid+1,right);
        }
}
void merge_sort(int A[],int N)
{
        auto tmp=new int[N];
        if(tmp){
                divide(A,tmp,0,N-1);
                delete tmp;
        }
}

int main()
{
        int n;
        cin>>n;
        int A[n];
        for (int i = 0; i < n; i++) {
                scanf("%d",&A[i]);
        }
        merge_sort(A,n);
        for (auto i:A){
                cout<<i<<" ";
        }
        cout<<endl;
        return 0;
}
