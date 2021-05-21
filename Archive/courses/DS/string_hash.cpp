#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

long long hash_string(char str[],int len)
{
    long long id=0;
    for(int i=0;i<len;i++){
        if(islower(str[i])){
            id=id*62+(str[i]-'a')+26;
        }
        if(isupper(str[i])){
            id=id*62+(str[i]-'A');
        }
        else if(isdigit(str[i])){
            id=id+(str[i]-'0');
        }
    }
    return id;
}

int main()
{
    char str[4]="BCD";
    long long id1=hash_string(str,3);
    cout<<id1<<endl;

    char str2[5]="BCD4";
    long long id2=hash_string(str2,4);
    cout<<id2<<endl;

    system("pause");
    return 0;
}