
#include<stdio.h>
int insert(int x, int* p,int *r) {
        int * tmp=p;
        for (; tmp > r; tmp--){
                if (x == *tmp) return 1;
        }
        for (; *p > x; p--)
                *(p + 1) = *p;
        *(p + 1) = x;
        return 0;
}
int main() {
        int n,flag;
        scanf("%d", &n);
        int a[500] = { 1 };
        for (int i = 0, j = 0; i < 400; j++) {
                flag=insert(2 * a[j] + 1, &a[i++],a);
                if (flag)i--;
                flag=insert(3 * a[j] + 1, &a[i++],a);
                if (flag)i--;
        }
        for (int i = 0; i < n; i++){
                printf("%d", a[i]);
                if (i != n - 1) printf(" ");
        }
        return 0;
}