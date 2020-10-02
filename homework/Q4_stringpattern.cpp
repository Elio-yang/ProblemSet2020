#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100010

// int* build_next(char *P);
int kmp(char *T,char *P);
int* fail_num(char *p);
int main()
{

    char txt[maxn];
    char pat[maxn];
    scanf("%s",txt);
    scanf("%s",pat);
    int *fail=fail_num(pat);
    int len=strlen(pat);
    for(int i=0;i<len;i++){
        cout<<fail[i]<<" ";
    }
    free(fail);
    cout<<endl;
    int pos=kmp(txt,pat);
    cout<<pos;
    system("pause");
    return 0;
}
int* build_next(char *P)
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
int kmp(char * t, char * p) 
{
	int i = 0; 
	int j = 0;
    int m=(int)strlen(p);
    int n=(int)strlen(t);
    int *next=build_next(p);
	while (i < n && j < m)
	{
		if (j == -1 || t[i] == p[j]){
			i++;
           	j++;
		}
	 	else{
           	j = next[j];
    	}
    }
    if (j == (int)strlen(p))
       return i - j;
    else 
       return -1;
}
int* fail_num(char *str){
    int len=strlen(str);
    int* arr=new int[len];
    arr[0]=-1;
    for(int j=1;j<len;j++){
        int i=arr[j-1];
        while(*(str+j)!=*(str+i+1)&&i>=0) i=arr[i] ;  //递推计算
        if(*(str+j)==*(str+i+1))arr[j]=i+1;  
        else arr[j]=-1;
    }
    return arr;
}