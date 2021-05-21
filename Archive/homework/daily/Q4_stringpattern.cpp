#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100010

int* build_next(char *P);
int* build_next_improve(char *P);
int KMP(char *T,char *P);
int* build_fail(char *p);

int main()
{
    char txt[maxn];
    char pat[maxn];
    scanf("%s",txt);
    scanf("%s",pat);
    int len=strlen(pat);
/*===========================================================================*/
    int *fail=build_fail(pat);
    cout<<"fail_table: ";
    for(int i=0;i<len;i++){
        cout<<fail[i]<<" ";
    }
    cout<<endl;
/*===========================================================================*/
    cout<<"next table :";
    int *next=build_next(pat);
    for(int i=0;i<len;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
/*===========================================================================*/
    cout<<"next table 2 :";
    int *next2=build_next_improve(pat);
    for(int i=0;i<len;i++){
        cout<<next2[i]<<" ";
    }
    cout<<endl;
/*===========================================================================*/

    int pos=Match(txt, pat);
    cout<<pos<<endl;

    system("pause");
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
int *build_next_improve(char *P)
{
    int m=(int)strlen(P),j=0;
    int *N=new int[m];
    int t=N[0]=-1;
    while(j<m-1){
        if(0>t||P[j]==P[t]){
            j++;
            t++;
            N[j]=(P[t]!=P[j])?t:N[t];
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
int KMP(char * T, char * P) 
{
	int i = 0; 
	int j = 0;
    int m=(int)strlen(P);
    int n=(int)strlen(T);
    int *next=build_next_improve(P);
	while (i < n && j < m)
	{
		if (0 > j || T[i] == P[j]){
			i++;
           	j++;
		}
	 	else{
           	j = next[j];
    	}
    }
    if (j == m){
       return i - j;
    }
    else {
       return -1;
    }
}
