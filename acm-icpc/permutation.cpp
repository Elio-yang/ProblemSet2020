/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/14
 */

#include <algorithm>
#include <cstdio>

using namespace std;

void permutation_stl(int arr[],size_t size)
{
        sort(arr,arr+size);
        do{
                for(int i=0;i<static_cast<int>(size);i++){
                        printf("%4d",arr[i]);
                }
                printf("\n");
        } while (next_permutation(arr,arr+size));
}

void swap(int* a,int* b)
{
        int tmp=*a;
        *a=*b;
        *b=tmp;
}

/*
 * s : start
 * e : end
 */
void permutation(int arr[],int s,int e)
{
        if (s==e){
                for(int i=0;i<=e;i++){
                        printf("%4d",arr[i]);
                }
                printf("\n");
                return;
        }
        else{
                for(int j=s;j<=e;j++){
                        /*
                         * swap the current num with position j
                         */
                        swap(&arr[s],&arr[j]);
                        permutation(arr,s+1,e);
                        /*
                         * backtrace
                         */
                        swap(&arr[s],&arr[j]);
                }
        }
}

int main()
{
        int test_arr[]={2,5,8,3};
        permutation_stl(test_arr, sizeof(test_arr)/ sizeof(test_arr[0]));
        permutation(test_arr,0,3);
        return 0;
}
