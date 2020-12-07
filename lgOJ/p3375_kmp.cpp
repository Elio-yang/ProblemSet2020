#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> ans;
#define maxn 1000010

int* build_next(char *P);
int* build_next_improve(char *P);
void KMP(char *T,char *P);
int* build_fail(char *p);

int main()
{
    char txt[maxn];
    char pat[maxn];
    scanf("%s",txt);
    scanf("%s",pat);
    int len=strlen(pat);

    Match(txt, pat);
    if(!ans.empty()){
        for(vector<int>::iterator it=ans.begin();it!=ans.end();++it){
            cout<<*it+1<<endl;
        }
    }
    /*都不匹配则不输出*/

    int *fail=build_fail(pat);
    for(int i=0;i<len;i++){
        cout<<fail[i]+1<<" ";
    }
    cout<<endl;

//    system("pause");
    return 0;
}
int *build_next(char *P)
{
    int m=(int)strlen(P),j=0;
    int *N=new int[m];
    int t=N[0]=-1;
    while(j<m-1){
        if(0>t||P[j]==P[t]){
            j++;
            t++;
            N[j]=t;
        }else{
            t=N[t];
        }
    }
    return N;
}

int *build_fail(char *P){
    int len=(int)strlen(P);
    int* F=new int[len];
    F[0]=-1;
    for(int j=1;j<len;j++){
        int i=F[j-1];
        while(P[j]!=P[i+1]&&i>=0) {
            i=F[i] ;
        }  
        if(P[j]==P[i+1]){
            F[j]=i+1;  
        }
        else {
            F[j]=-1;
        }
    }
    return F;
}
void KMP(char * T, char * P) 
{
        int i = 0; 
	    int j = 0;
        int m=(int)strlen(P);
        int n=(int)strlen(T);
        int *next=build_next(P);
        while (i < n){
            if (0 > j || T[i] == P[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
            if(j==m){
                /*多次匹配*/
                ans.push_back(i-j);
                j=next[j-1];
                i--;
            }
        }
}
