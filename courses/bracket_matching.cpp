#include <iostream>
#include <cstdlib>

#include <stack>
using namespace std;
stack<char>left_bracket;
bool matching(const char* str);
int main()
{
    char str[100];
    scanf("%s",str);
    printf("matching %s ans: ",str);
    cout<<matching(str)<<endl;
    system("pause");
    return 0;
}
bool matching(const char* str)
{
    while(*str!='\0'){
        if(*str=='('||*str=='['||*str=='{'){
            left_bracket.push(*str);
        }
        else if(*str==')'||*str==']'||*str=='}'){
            char tmp=left_bracket.top();
            left_bracket.pop();
            switch (tmp)
            {
            case '(':
                if(*str!=')'){
                    return false;
                }
                break;
            case '[':
                if(*str!=']'){
                    return false;
                }
                break;
            case '{':
                if(*str!='}'){
                    return false;
                }
                break;
            }    
        }
        str++;
        
    }
    if(!left_bracket.empty()){
        return false;
    }
    return true;
}
