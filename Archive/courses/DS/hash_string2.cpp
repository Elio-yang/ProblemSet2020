#include <iostream>
#include <map>
using namespace std;
map<const char*,int> hashmap;
const int maxn=100;
char tmp[4];
char str[maxn][4];

int main()
{
    int n,m;
    for(int i=0;i<n;i++){
        cin>>str[i];
       ++hashmap[str[i]];
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        cout<<hashmap[tmp]<<endl;
    }
    return 0;
}