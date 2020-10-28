#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool mycmp(int a,int b)
{
        return a<b;
}
int main()
{
        char str[4];
        while(scanf("%s",str)!=EOF){
              int c1=str[0]-'\0';
              int c2=str[1]-'\0';
              int c3=str[2]-'\0';
              int arr[3]={c1,c2,c3};
              sort(arr,arr+3,mycmp);
              printf("%c %c %c\n",(char)arr[0],(char)arr[1],(char)arr[2]);
        }

        return 0;
}