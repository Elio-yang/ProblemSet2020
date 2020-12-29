#include <cstdio>
#include <climits>
void swap(int *a, int *b)
{
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

int find_min( const int a[], int beg, int end)
{
        int i = -1;
        int min = INT_MAX;

        for (int j = beg; j < end; j++) {
                if (a[j] < min) {
                        min=a[j];
                        i = j;
                }
        }
        return i;
}

int find_max( const int a[], int beg, int end)
{
        int i = -1;
        int max = INT_MIN;
        for (int j = beg; j < end; j++) {
                if (a[j] > max) {
                        max=a[j];
                        i = j;
                }
        }
        return i;
}

void selection_sort(int a[], int n, int(*cmp)( const int a[], int beg, int end))
{
        int beg;
        int end = n;
        for (int i = 0; i < end; i++) {
                beg = i;
                int index = cmp(a, beg, end);
                swap(&a[i], &a[index]);
        }
}

void bubble_sort( int a[], int n)
{
        bool sorted = false;
        while (!sorted) {
                sorted = true;
                for (int i = 1; i < n; i++) {
                        if (a[i - 1] > a[i]) {
                                swap(&a[i - 1], &a[i]);
                                sorted = false;
                        }

                }
                n--;
        }
}

void insert_sort( int a[], int n)
{
        //！i=1开始
        for (int i = 1; i < n; i++) {
                int tmp = a[i];
                int j = i;
                while (j >= 0 && a[j - 1] > tmp) {
                        a[j] = a[j - 1];
                        j--;
                }
                a[j] = tmp;
        }
}

int main()
{
        int arr[]={-387,2332,455,-2,-5,-9,24,-4,-3,-4,-4,-4,77,8,92,-1,0,0,0,0,87,23456};
        for(auto i:arr){
                printf("%d ",i);
        }
        printf("\n");
        /*-----------------------------------------------------------*/
        selection_sort(arr,sizeof(arr)/ sizeof(arr[0]),find_min);
        for(auto i:arr){
                printf("%d ",i);
        }
        printf("\n");
        /*-----------------------------------------------------------*/
        int arr2[]={-387,2332,455,-2,-5,-9,24,-4,-3,-4,-4,-4,77,8,92,-1,0,0,0,0,87,23456};
        selection_sort(arr2,sizeof(arr2)/ sizeof(arr2[0]),find_max);
        for(auto i:arr2){
                printf("%d ",i);
        }
        printf("\n");
        /*-----------------------------------------------------------*/
        int arr3[]={-387,2332,455,-2,-5,-9,24,-4,-3,-4,-4,-4,77,8,92,-1,0,0,0,0,87,23456,1};
        bubble_sort(arr3,sizeof(arr3)/ sizeof(arr3[0]));
        for(auto i:arr3){
                printf("%d ",i);
        }
        printf("\n");
        /*-----------------------------------------------------------*/
        int arr4[]={-387,2332,455,-2,-5,-9,24,-4,-3,-4,-4,-4,77,8,92,-1,0,0,0,0,87,23456};
        insert_sort(arr4,sizeof(arr4)/ sizeof(arr4[0]));
        for(auto i:arr4){
                printf("%d ",i);
        }
        printf("\n");
        return 0;
}