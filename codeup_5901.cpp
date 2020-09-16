#include<bits/stdc++.h>
using namespace std;
#define MAX 256
string isC1(string s)
{
        string::size_type len=s.end()-s.begin();
        int i;
        bool flag=true;
        for(i=0;i<len/2;i++){
                if(s[i]!=s[len-1-i]){
                        flag=false;
                        break;
                }
        }
        return flag?"YES":"NO";
}
string isC2(char str[])
{
        bool flag=true;
        int len=strlen(str);
        for (int i = 0; i < len/2;i++)
        {
                if(str[i]!=str[len-1-i]){
                        flag=false;
                        break;
                }
        }
        return flag?"YES":"NO";
}

int main()
{
        string s("level");
        cout<<isC1(s)<<endl;
        string s2("hello");
        cout<<isC1(s2)<<endl;
        char str[]="lllllllolllllll";
        cout<<isC2(str)<<endl;
        
        return 0;
}