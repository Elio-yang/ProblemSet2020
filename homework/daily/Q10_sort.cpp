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

//#include <cstdio>
//#include <cstring>
//void MERGE(int *arr, int *tmp, int beg, int end) {
//        if (beg >= end){return;}
//        int len = end - beg, mid = (len >> 1) + beg;
//        int beg_1 = beg, end_1 = mid;
//        int beg_2 = mid + 1, end_2 = end;
//        MERGE(arr, tmp, beg_1, end_1);
//        MERGE(arr, tmp, beg_2, end_2);
//        int id = beg;
//        while (beg_1 <= end_1 && beg_2 <= end_2){
//                if(arr[beg_1] < arr[beg_2]){
//                        tmp[id++]=arr[beg_1++];
//                }else{
//                        tmp[id++]=arr[beg_2++];
//                }
//        }
//        while (beg_1 <= end_1) {
//                tmp[id++] = arr[beg_1++];
//        }
//        while (beg_2 <= end_2){
//                tmp[id++] = arr[beg_2++];
//        }
//        for (id = beg; id <= end; id++){
//                arr[id] = tmp[id];
//        }
//}
//
//void merge(int *un_sorted,int len) {
//        int tmp[len];
//        MERGE(un_sorted, tmp, 0, len - 1);
//}
//
//int main()
//{
//        int n;
//        scanf("%d",&n);
//        int un_sorted[n];
//        memset(un_sorted,0,sizeof(un_sorted));
//        for(int i=0;i<n;i++){
//                scanf("%d",&un_sorted[i]);
//        }
//        merge(un_sorted,n);
//        for(int i:un_sorted){
//                printf("%d ",i);
//        }
//        return 0;
//}
