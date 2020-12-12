// C Program to illustrate Generic Quicksort Function
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int cmp(void* s1, void* s2)
{
        // casting s1 to int* so it can be
        // copied in variable a.
        int *a = (int*)s1;
        int *b = (int*)s2;
        if ((*a) > (*b))
                return 1;
        else if ((*a) < (*b))
                return -1;
        else
                return 0;
}

// function for swap two elements
void swap(void* v1, void* v2, int size)
{
        /*
         * buffer is array of characters which will
         * store element byte by byte
         * memcpy will copy the contents from starting
         * address of v1 to length of size in buffer
         * byte by byte.
         * */
        char buffer[size];


        memcpy(buffer, v1, size);
        memcpy(v1, v2, size);
        memcpy(v2, buffer, size);
}
/*
 * v is an array of elements to sort.
 * size is the number of elements in array
 * left and right is start and end of array
 * (*comp)(void*, void*) is a pointer to a function
 * which accepts two void* as its parameter
 */
void _qsort(void* v, int size, int left, int right,
            int (*comp)(void*, void*))
{
        void *vt, *v3;
        int i, last, mid = (left + right) / 2;
        if (left >= right)
                return;

        // casting void* to char* so that operations
        void* vl = (char*)(v + (left * size));
        void* vr = (char*)(v + (mid * size));
        swap(vl, vr, size);
        last = left;
        for (i = left + 1; i <= right; i++) {

                /*
                 * vl and vt will have the starting address
                 * of the elements which will be passed to
                 * comp function.
                 */
                vt = (char*)(v + (i * size));
                if ((*comp)(vl, vt) > 0) {
                        ++last;
                        v3 = (char*)(v + (last * size));
                        swap(vt, v3, size);
                }
        }
        v3 = (char*)(v + (last * size));
        swap(vl, v3, size);
        _qsort(v, size, left, last - 1, comp);
        _qsort(v, size, last + 1, right, comp);
}

/*just use it like it used to be! the same interface as what in stdlib.h*/
void qsort(void* _base, std::size_t _nmemb, std::size_t _size, int (*_cmp)(void*, void*)){
        _qsort(_base, _size, 0, _nmemb - 1, _cmp);
}

int main()
{
        int n;
        cin>>n;
        int A[n];
        for (int i = 0; i < n; i++) {
                scanf("%d",&A[i]);
        }
        int *P=A;
        //_qsort(P,sizeof(A[0]),0,n-1,(int (*)(void*, void*))(cmp));
        qsort(P, n, sizeof(P[0]), cmp);
        for (auto i:A){
                cout<<i<<" ";
        }
        return 0;
}