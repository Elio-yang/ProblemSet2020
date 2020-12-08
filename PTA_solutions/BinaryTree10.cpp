/*
 ## 哈夫曼树 (10分)

编写一个哈夫曼编码译码程序。针对一段文本，根据文本中字符出现频率构造哈夫曼树，给出每个字符的哈夫曼编码，并进行译码，计算编码前后文本大小。 为确保构建的哈夫曼树唯一，本题做如下限定：

1. 选择根结点权值最小的两棵二叉树时，选取权值较小者作为左子树。
2. 若多棵二叉树根结点权值相等，则先生成的作为左子树，后生成的作为右子树，具体来说：i) 对于单结点二叉树，优先选择根结点对应字母在文本中最先出现者，如文本为cba，三个字母均出现1次，但c在文本中最先出现，b第二出现，故则选择c作为左子树，b作为右子树。ii) 对于非单结点二叉树，先生成的二叉树作为左子树，后生成的二叉树作为右子树。iii. 若单结点和非单结点二叉树根结点权值相等，优先选择单结点二叉树。
3. 生成哈夫曼编码时，哈夫曼树左分支标记为0，右分支标记为1。

### 输入格式:

输入为3行。第1行为一个字符串，包含不超过5000个字符，至少包含两个不同的字符，每个字符为a-z的小写字母。第2、3行为两个由0、1组成的字符串，表示待译码的哈夫曼编码。

### 输出格式:

输出第一行为用空格间隔的2个整数，分别为压缩前后文本大小，以字节为单位，一个字符占1字节，8个二进制位占1字节，若压缩后文本不足8位，则按1字节算。输出从第二行开始，每行为1个字符的哈夫曼编码，按各字符在文本中出现次数递增顺序输出，若多个字符出现次数相同，则按其在文本出现先后排列。每行格式为“字母:编码”。最后两行为两行字符串，表示译码结果，若译码失败，则输出INVALID。

### 输入样例:

```in
cbaxyyzz
0100
011
```

### 输出样例:

```out
8 3
c:100
b:101
a:110
x:111
y:00
z:01
zy
INVALID
```

```cpp
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5210
struct Huffman{
    struct Huffman* llink;
    char info;
    int weight;
    struct Huffman* rlink;
};
struct Huffman* create(char pat[M],int h[M],int count)
{
    int i,j;
    struct Huffman* H[count];
    struct Huffman* p;
    for(i=0;i<count;i++)
    {
        H[i]=(struct Huffman*)malloc(sizeof(struct Huffman));
        H[i]->llink=NULL;
        H[i]->info=pat[i];
        H[i]->weight=h[i];
        H[i]->rlink=NULL;
    }
    for(i=0;i<count-1;i++)
    {
        struct Huffman* t;
        t=(struct Huffman*)malloc(sizeof(struct Huffman));
        t->weight=H[i]->weight+H[i+1]->weight;
         t->llink=H[i];
         t->rlink=H[i+1];
        j=i+2;
        while(j!=count&&(t->weight>=H[j]->weight))
        {
            H[j-1]=H[j];
            j=j+1;
        }
        H[j-1]=t;
    }
    return H[count-1];
}
int sum=0;
int calculate(struct Huffman* t,int depth)
     {
         if(t->llink==NULL)
            return sum+=depth*t->weight;
            calculate(t->llink,depth+1);
            calculate(t->rlink,depth+1);
     }
int t3=0;
char b[][26];
char c[26];
 void path(struct Huffman*t,int a[],char pat[],int i,int depth,int flag,int count)
 {
     int j,k;
     if(flag==0)
        a[i]=0;
     else
        a[i]=1;
     if(t->llink==NULL)
     {
       c[t3++]=t->info;
         int t2=1;
           b[t3-1][0]=depth;
         for(j=1;j<=depth;j++)
             b[t3-1][t2++]=a[j];
        return ;
       }
         path(t->llink,a,pat,i+1,depth+1,0,count);
         path(t->rlink,a,pat,i+1,depth+1,1,count);

 }
void code(struct Huffman* t,char cd[])
{
int i,q,count2=0;
char hnm[M];
struct Huffman* r=t;
q=strlen(cd);
for(i=0;i<q;i++)
{
if(cd[i]=='0')
r=r->llink;
else
r=r->rlink;
if(r->llink==NULL)
{
hnm[count2++]=r->info;
r=t;
continue;
}
if(t->llink!=NULL&&i==q-1)
{
printf("INVALID\n");
return ;
}
}
hnm[count2]='\0';
printf("%s",hnm);
printf("\n");
}


int main()
{
    int i,j,k,temp;
    char ch;
    char str[M],pat[M];
    scanf("%s",str);
    int m,count=0,t=0,n=0;
    m=strlen(str);
    int w[M]={0};
    int h[M];
    int flag;
    for(i=0;i<m;i++)
    {
        flag=1;
        for(k=0;k<i;k++)
        {
            if(str[i]==str[k]){
            w[i]=0;
            flag=0;}
        }
        if(flag==1)
        {
        count++;
        for(j=i;j<m;j++)
        if(str[i]==str[j])
        w[i]++;
        }
    }
    for(i=0;i<m;i++)
    {
        if(w[i]!=0)
        {
            pat[t++]=str[i];
            h[n++]=w[i];
        }
    }
    for(i=0;i<count-1;i++)
        for(j=0;j<count-1-i;j++)
    {
        if(h[j]>h[j+1])
        {
            temp=h[j];
            h[j]=h[j+1];
            h[j+1]=temp;
            ch=pat[j];
            pat[j]=pat[j+1];
            pat[j+1]=ch;
        }
    }
        struct Huffman* p;
        p=(struct Huffman*)malloc(sizeof(struct Huffman));
        p=create(pat,h,count);
        int depth =0;
        int sum1=calculate(p,depth);
        printf("%d %d\n",m,sum1/8+1);
        int a[M];
       path(p,a,pat,0,0,0,count);
       for(i=0;i<count;i++)
       {
           printf("%c:",pat[i]);
           for(k=0;k<count;k++){
            if(c[k]==pat[i])
           for(j=1;j<b[k][0]+1;j++)
           {
            printf("%d",b[k][j]);
           }
           }
           printf("\n");
       }
       char cd1[M];
       char cd2[M];
       scanf("%s",cd1);
       scanf("%s",cd2);
       code(p,cd1);
       code(p,cd2);
}
