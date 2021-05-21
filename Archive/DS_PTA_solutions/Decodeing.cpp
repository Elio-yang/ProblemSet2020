/*
 小明接到一个破解报文的任务：该报文是一串文本，破解出的密文应是在报文串中
 出现次数大于1的所有子串中的最长者。规定报文本身不能称为自己的子串。请编
 写效率尽可能高的程序帮小明完成这个棘手的任务。

输入格式:
输入为一个字符串，表示报文，包含不超过10000个字母。

输出格式:
输出为一个整数，表示破解出的密文串的长度。

输入样例1:
xabceabcf
输出样例1:
3

输入样例2:
xyabcabcayx
输出样例2:
4
 */
/*
 * @Author: alone_yue
 * @Date: 2020-11-05 08:17:23
 */
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int ne[100010];


int getne(char pattern[])
{
        int m=strlen(pattern);
        int max=0;
        ne[0]=-1;
        int j=-1;
        for(int i=1;i<m;i++){
                while (j!=-1&&pattern[i]!=pattern[j+1]) j=ne[j];

                if(pattern[i]==pattern[j+1]) j++;
                //if(j==-1) ne[i]=j;
                ne[i]=j;
                if(ne[i]>max) max=ne[i];
        }
        return max;
}
int main(){
        char t[10000];
        scanf("%s",t); int maxn=0;
        for(int i=0;i<strlen(t);i++){
                if(getne(t+i)>maxn) maxn=getne(t+i);
        }
        printf("%d",maxn+1);
        system("pause");
        return 0;
}
//abcabcqwerqwer
