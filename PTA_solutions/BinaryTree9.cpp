/*
 ## 二叉树路径和 (10分)

编写程序找出二叉树中和最大的路径，二叉树结点为不等于0的整数。本题的“路径”限定为以根结点为起点，以叶结点为终点的路径。路径的和，即该路径所包含的所有结点的数据值之和。

### 输入格式:

输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。

### 输出格式:

输出为两行，第一行为该二叉树路径和的最大值，第二行为一组整数，每个整数后一个空格，即该最大路径包含的结点值（按从根的叶的顺序），如果存在多条满足条件路径，则输出最左边一条。

### 输入样例1:

```in
1 2 0 0 3 0 0
```

### 输出样例1:

```out
4
1 3
```

### 输入样例2:

```in
-1 2 0 0 3 0 0
```

### 输出样例2:

```out
2
-1 3
```

 */
#include <cstdlib>
#include <iostream>
struct node{
        int key;
        struct node *lchild;
        struct node *rchild;
};
using namespace std;
struct node* creat();
void printPathRecur(struct node *node, int path[], int len);


int ans[100][100];
int len_id[100];
int id=0;


int main()
{
        auto *T=(struct node *)malloc(sizeof(struct node));
        T=creat();
        int path[110]={0};
        printPathRecur(T,path,0);
        int max=INT32_MIN;
        int id_m=0;
        for(int i=0;i<id;i++){
                int result=0;
                for(int j=0;j<100;j++){
                        result+=ans[i][j];
                }
                if(result>max){
                        max=result;
                        id_m=i;
                }
        }

        cout<<max<<endl;
        for(int i=0;i<len_id[id_m];i++){
                cout<<ans[id_m][i]<<" ";
        }
        cout<<endl;
        return 0;
}

struct node* creat()
{
        int k;
        scanf("%d",&k);
        struct node* T;

        if(k==0){
                T= NULL;
        }else{
                T=(struct node*)malloc(sizeof(struct node));
                T->key=k;
                T->lchild=creat();
                T->rchild=creat();
        }
        return T;
}



void printPathRecur(struct node *node, int path[], int len)
{
        if (node == NULL) return;
        path[len] = node->key;
        len++;

        if (node->lchild ==NULL && node->rchild == NULL)
        {
                for(int i=0;i<len;i++){
                        ans[id][i]=path[i];
                }
                len_id[id]=len;
                id++;
        } else {
                printPathRecur(node->lchild, path, len);
                printPathRecur(node->rchild, path, len);
        }
}
