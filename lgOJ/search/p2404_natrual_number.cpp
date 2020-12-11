// TODO FIGURE IT OUT
#include<iostream>
using namespace std;
int a[10001]= {1},n,total;
void print(int t) {
        for(int i=1; i<=t-1; i++)//输出一种方案解
                cout<<a[i]<<'+';
        cout<<a[t]<<endl;
        total++;//方案数加一
}
void search(int s,int t) {
        for(int i=a[t-1]; i<=s; i++)
                if(i<n) {//当前数 i 要大于等于前 1 位数，且不超过 n
                        a[t]=i;//保存当前拆分数 i
                        s-=i;// s 减去数 i，s 的值继续拆分
                        if(s==0) print(t);//当 s=0 时，拆分结束输出结果
                        else search(s,t+1);//当 s>0 时，继续递归
                        s+=i;//回溯：加上拆分的数，以便产生所有可能的拆分
                }
}
int main() {
        cin>>n;
        search(n,1);//将要拆分的数 n 传递给 s
        return 0;
}