#include <cstdio>
#include <cctype>
#include <cstring>
char keyw[32][10]={
        "auto", "double", "int", "struct" ,"break" ,"else",
        "long", "switch","case", "enum", "register", "typedef",
        "char", "extern", "return", "union","const", "float", "short",
        "unsigned", "continue", "for", "signed", "void","default", 
        "goto", "sizeof", "volatile", "do", "if", "while", "static"
};
int main()
{
        int n;
        scanf("%d",&n);
        getchar();
        for(int j=0;j<n;j++){
                char str[55];
                char ch;
                int i=0;
                bool f=true;
                while((ch=getchar())!='\n'){
                        str[i]=ch;
                        if(!isalpha(ch)&&!isdigit(ch)&&(ch!='_')){
                                f=false;
                        }
                        i++;
                }
                str[i]='\0';
                if(isdigit(str[0])){
                        f=false;
                }
                for(int i=0;i<32;i++){
                        if(strcmp(str,keyw[i])==0){
                                f=false;
                                break;
                        }
                }
                printf("%s\n",(f)?("yes"):("no"));
        }
        return 0;
}