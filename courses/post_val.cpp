
#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
stack<int>op_val;
double add(double a,double b);
double subtrac(double a,double b);
double mult(double a, double b);
double devide(double a,double b);
double call_f(double (*f_ptr)(double a,double b),double op1,double op2);
int main()
{   
    char *ops=(char*)malloc(sizeof(char)*100);
    scanf("%s",ops);
    while(*ops!='\0'){
        if(isdigit(*ops)){
            op_val.push(*ops-'0');
        }
        else if(*ops=='+'||*ops=='-'||*ops=='*'||*ops=='/'){
            int ans=0;
            int num1=0;
            int num2=0;
            num1=op_val.top();
            op_val.pop();
            num2=op_val.top();
            op_val.pop();
            switch (*ops)
            {
            case '+':
                ans=call_f(add,num1,num2);
                op_val.push(ans);
                break;
            case '-':
                ans=call_f(subtrac,num1,num2);
                op_val.push(ans);
                break;
            case '*':
                ans=call_f(mult,num1,num2);
                op_val.push(ans);
                break;
            case '/':
                ans=call_f(devide,num1,num2);
                op_val.push(ans);
                break;
            }
        }
        ops++;
    }
    cout<<op_val.top()<<endl;
    system("pause");
    return 0;
}
double add(double a,double b)
{
    return (a+b);
}
double subtrac(double a,double b)
{
    return (a-b);
}
double devide(double a,double b)
{
    return a/b;
}
double mult(double a, double b)
{
    return (a*b);
}
double call_f(double (*f_ptr)(double a,double b),double op1,double op2)
{   
    return f_ptr(op1,op2);
}