#include <cstdio>
#include <cstring>
void MERGE(int *arr, int *tmp, int beg, int end) {
        if (beg >= end){return;}
        int len = end - beg, mid = (len >> 1) + beg;
        int beg_1 = beg, end_1 = mid;
        int beg_2 = mid + 1, end_2 = end;
        MERGE(arr, tmp, beg_1, end_1);
        MERGE(arr, tmp, beg_2, end_2);
        int id = beg;
        while (beg_1 <= end_1 && beg_2 <= end_2){
                if(arr[beg_1] < arr[beg_2]){
                        tmp[id++]=arr[beg_1++];
                }else{
                        tmp[id++]=arr[beg_2++];
                }
        }
        while (beg_1 <= end_1) {
                tmp[id++] = arr[beg_1++];
        }
        while (beg_2 <= end_2){
                tmp[id++] = arr[beg_2++];
        }
        for (id = beg; id <= end; id++){
                arr[id] = tmp[id];
        }
}

void merge(int *un_sorted,int len) {
        int tmp[len];
        MERGE(un_sorted, tmp, 0, len - 1);
}

int main()
{
        int n;
        scanf("%d",&n);
        int un_sorted[n];
        memset(un_sorted,0,sizeof(un_sorted));
        for(int i=0;i<n;i++){
                scanf("%d",&un_sorted[i]);
        }
        merge(un_sorted,n);
        for(int i:un_sorted){
                printf("%d ",i);
        }
        return 0;
}
