#include <iostream>
#include <cctype>
#include <stack>
#define is_ops(str)    ((str=='+')||(str=='-')||(str=='*'||(str=='/')))
#define is_lbrac(str)  ( (str=='(') )
#define is_rbrac(str)  ( (str==')') )
#define is_bracs(str)   (is_lbrac(str)||is_rbrac(str))
#define order(op) ({int m;                      \
                    if(op=='+'||op=='-'){       \
                        m=1;                    \
                    }                           \
                    else if(op=='*'||op=='/'){  \
                        m=2;                    \
                    }                           \
                    else if(op=='('){           \
                        m=0;                    \
                    }                           \
                    m;})
using namespace std;

stack<char>ops;
void mid_to_post(const char* str);

int main()
{
        char str[]="(a+b)*((c-d)*e+f)";
        cout<<"mid_t expression: "<<str<<endl;
        cout<<"post_t expression: ";
        mid_to_post(str);
        system("pause");
        return 0;
}
void mid_to_post(const char* str)
{
        while(*str!='\0'){
                if(isalpha(*str)){
                        cout<<*str;
                        str++;
                }
                else if(is_ops(*str)){
                        if(ops.empty()){
                                ops.push(*str);
                                str++;
                        }else{
                                if(order(*str)>order(ops.top())){
                                        ops.push(*str);
                                        str++;
                                }else{
                                        cout<<ops.top();
                                        ops.pop();
                                }
                        }
                }
                else if(is_bracs(*str)){
                        if(is_lbrac(*str)){
                                ops.push(*str);
                        }
                        else if(is_rbrac(*str)){
                                while(ops.top()!='('){
                                        cout<<ops.top();
                                        ops.pop();
                                }
                                ops.pop();
                        }
                        str++;
                }
        }
        while(!ops.empty()){
                cout<<ops.top();
                ops.pop();
        }
        cout<<endl;
}
