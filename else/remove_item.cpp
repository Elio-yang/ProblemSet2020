#include <iostream>
#include <cstdlib>
using namespace std;

#define N 100
#define ITEM 10086
#define data_t int
struct table{
    data_t size;
    data_t* arr;
};

void remove_item(struct table* T,data_t item);
void print_table(struct table* T);
struct table *creat_table(data_t size,data_t item);
int main()
{
    struct table *T=creat_table(N,ITEM);
    cout<<"原数组大小"<<T->size<<" 原数组为: "<<endl;
    print_table(T);
    cout<<"删除ITEM="<<ITEM<<"后"<<endl;
    remove_item(T,ITEM);
    cout<<"数组大小"<<T->size<<" 数组为: "<<endl;
    print_table(T);
    system("pause");
    return 0;
}
void remove_item(struct table* T,data_t item)
{
    /*j to point item*/
    int i=0;
    int j=0;
    int k;
    /*cnt to store number of item*/
    int cnt=0;
    for(k=0;k<T->size;k++){
        if(T->arr[k]==item){
            i++;
            cnt++;
        }else{
            /* i points to another element which is not equal to item
             * but j points to item so replace arr[j] by arr[i] 
             */
            T->arr[j]=T->arr[i];
            i++;
            j++;
        }
    }
    T->size-=cnt;
}
void print_table(struct table* T)
{
    for(int i=0;i<T->size;i++){
        printf("%-6d",T->arr[i]);
        if(i%10==9){
            cout<<endl;
        }
    }
    cout<<endl;
}
struct table *creat_table(data_t size,data_t item)
{
    struct table * T=(struct table*)malloc(sizeof(struct table));
    T->size=size;
    T->arr=(data_t *)malloc(sizeof(data_t)*size);
    for(int i=0;i<size;i++){
        if(i%2==0){
            T->arr[i]=item;
        }else{
            T->arr[i]=i;
        }
    }
    return T;
}
