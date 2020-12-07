/*pre_order*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#include <stack>

using namespace std;
stack<double> value;

int main()
{       
        string s1;
        bool f=false;
        string polish_str[100];
        int n=0;
        while(cin>>polish_str[n++]){}
        n--;
        for(int i=n-1;i>=0;i--){
                if(isdigit(polish_str[i][0])){
                        value.push(atof(polish_str[i].c_str()));
                }
                else{
                        if(value.size()<2){f=true;break;}
                        /*注意错误处理*/
                        char c=polish_str[i][0];

                        double op1=value.top();
                        value.pop();
                        double op2=value.top();
                        value.pop();

                        double ans=0.0;
                        switch(c){
                                case '+':{
                                        ans=op1+op2;
                                        value.push(ans);
                                        break;
                                }
                                case '-':{
                                        ans=op1-op2;
                                        value.push(ans);
                                        break;

                                }
                                case '*':{
                                        ans=op1*op2;
                                        value.push(ans);
                                        break;

                                }
                                case '/':{
                                        if(op2==0){
                                                f=true;
                                                break;
                                        }
                                        ans=op1/op2;
                                        value.push(ans);
                                        break;
                                }
                        }
                }
        }
       
       if(value.size()!=1){f=true;}
       /*错误处理*/
       if(f){
               printf("ERROR\n");
       }else{
                double l_v=value.top();
                printf("%f\n",l_v);
       }
       
       system("pause");
        return 0;

}