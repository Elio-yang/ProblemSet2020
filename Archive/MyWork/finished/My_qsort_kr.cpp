void swap(void*v[],int i,int j)
{
        void *tmp;
        tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
}
void Qsort(void **v, int left, int right, int(*cmp)(void *, void *))
{
        int i,last;
        if (left>=right){
                return;
        }
        swap(v,left,(left+right)/2);
        last=left;
        for (int j = left+1; j <=right ; j++) {
                if ((*cmp)(v[j],v[left])<0){
                        swap(v,++last,i);
                }
        }
        swap(v,left,last);
        Qsort(v, left, last - 1, cmp);
        Qsort(v, last + 1, right, cmp);
}
int cmp(void *a,void *b)
{
        return *((int *)a)-*((int*)b);
}

int main()
{
        int arr[]={2,4,5,666,7765,7434,5242,322,1345,67,78954,7,35,543};

}

