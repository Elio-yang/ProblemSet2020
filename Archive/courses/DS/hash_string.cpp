#include <iostream>
using namespace std;
const int maxn=100;
char tmp[4];
char str[maxn][4];
int hash_table[26*26*26+10];
int hash_t(const char *str);
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str[i];
        int id=hash_t(str[i]);
        ++hash_table[id];
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        int id=hash_t(tmp);
        cout<<hash_table[id]<<endl;
    }
    return 0;
}
int hash_t(const char *str)
{
    int val=0;
    while(*str!='\0'){
        val=val*26+(*str++-'A');
    }
    return val;
}
