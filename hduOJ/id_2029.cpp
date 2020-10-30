#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
        int n;
        cin>>n;
        getchar();
        while(n--){
                bool flag=true;
                string str;
                getline(cin,str);
                string::size_type t=str.length();
                for(std::string::size_type i=0;i<(t/2);i++){
                        if(str[i]!=str[t-1-i]){
                                flag=false;
                        }
                }
                printf("%s\n",(flag)?("yes"):("no"));       
        }

        return 0;
}