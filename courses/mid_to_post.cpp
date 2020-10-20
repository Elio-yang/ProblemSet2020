#include <iostream>
#include <cctype>
#include <stack>
#define belong_ops(str)    ((str=='+')||(str=='-')||(str=='*'||(str=='/')))
#define belong_lbrac(str)  ( (str=='(') )
#define belong_rbrac(str)  ( (str==')') )
#define belong_brac(str)   (belong_lbrac(str)||belong_rbrac(str))
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
                else if(belong_ops(*str)){
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
                else if(belong_brac(*str)){
                        if(belong_lbrac(*str)){
                                ops.push(*str);
                        }
                        else if(belong_rbrac(*str)){
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
