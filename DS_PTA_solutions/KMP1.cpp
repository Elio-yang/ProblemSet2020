/*
 ## 好中缀 (10分)

我们称一个字符串S的子串T为好中缀，如果T是去除S中满足如下条件的两个子串p和q后剩余的字符串。

（1）p是S的前缀，q是S的后缀；

（2）p=q；

（3）p和q是满足条件(1)(2)的所有子串中的第二长者。

注意一个字符串不能称为自己的前缀或后缀。好中缀至少为空串，其长度大于等于0，不能为负数。

### 输入格式:

输入为一个字符串S，包含不超过100000个字母。

### 输出格式:

输出为一个整数，表示好中缀的长度。

### 输入样例1:

```in
abcabcxxxabcabc
```

### 输出样例1:

```out
9
```

### 输入样例2:

```in
xacbacba
```

### 输出样例2:

```out
8
```

### 输入样例3:

```in
aaa
```

### 输出样例3:

```out
1
```

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
#define maxn 100010

int hash_t(const char *str,int len);
int* build_fail(char *p);

int main()
{
    char pat[maxn];
    scanf("%s",pat);
    int len=strlen(pat);

    int *fail=build_fail(pat);
    int max_len=fail[len-1]+1;
    //int ans[max_len+2]={0};

    pat[max_len]='\0';
    int *fail_d=build_fail(pat);

    int out_d;
    if(max_len==0){
            out_d=0;
    }else{
            out_d=fail_d[max_len-1]+1;

    }




//     for(int i=1;i<=max_len;i++){
//             int hash_sub=hash_t(pat,i-1);
//             int hash_fat=hash_t(pat+(len-1)-(i-1),i-1);
//             if(hash_sub==hash_fat){
//                     ans[i]=i;
//                     if(ans[i]>max1){
//                         int tmp=max1;
//                         max1=ans[i];
//                         max2=tmp;
//                     }
//             }
//     }

    int out=len-2*out_d;
    if(out<0){
            out=0;
    }
    printf("%d\n",out);
    system("pause");
    return 0;
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

int hash_t(const char *str,int len)
{
    int val=0;
    for(int i=0;i<=len;i++){
            val=val*26+(str[i]-'a');
    }
    return val;
}
