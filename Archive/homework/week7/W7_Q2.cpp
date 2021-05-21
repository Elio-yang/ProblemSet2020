#include <cstdio>

inline void swap(int*a,int*b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
}

void show(int a[],int size){
        for (int i = 0; i < size; i++) {
                printf("%d ",a[i]);
        }
        printf("\n");
}

void qsort(int A[],int m,int n,int size){
        if (m<n){
                int i=m;
                int j=n+1;
                int K=A[m];
                while (i<j){
                        ++i;
                        while (A[i]<=K){++i;}
                        --j;
                        while (A[j]>K){--j;}
                        if (i<j){
                                swap(&A[i],&A[j]);
                        }
                }
                swap(&A[m],&A[j]);

                show(A,size);

                qsort(A,m,j-1,size);
                qsort(A,j+1,n,size);
        }
}

int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        for (int i = 0; i < n; i++) {
                scanf("%d",&arr[i]);
        }
        qsort(arr,0,n-1,n);
        show(arr,n);
        return 0;

}