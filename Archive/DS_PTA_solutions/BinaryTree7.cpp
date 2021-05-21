/*
 ## A 重建二叉树 (10分)

给定二叉树的中根序列和后根序列，请编写程序创建该二叉树，计算其高度和先根序列，最后删除该二叉树；
 如给定的中根和后根序列不合法，则亦能识别。

### 输入格式:

输入为两行字符串，第一行表示某二叉树的后根序列，第二行表示其中根序列。结点的值均为A-Z的大写字母，
 故二叉树结点个数不超过26，且保证输入的两个序列都是结点的全排列，但不一定是合法的中根和后根序列。

### 输出格式:

如果输入的序列不合法（不是同一棵树的中根序列和后根序列），则输出INVALID。
 若输入序列合法，输出为两行，第一行为一个整数，表示该二叉树的高度，第二行为一个字符串，表示该二叉树的先根序列。

### 输入样例1:

```in
CEFDBHGA
CBEDFAGH
```

### 输出样例1:

```out
3
ABCDEFGH
```

### 输入样例2:

```in
CBEDFAGH
CEFDBHGA
```

### 输出样例2:

```out
INVALID
```

### 输入样例3:

```in
BCA
CAB
```

### 输出样例3:

```out
INVALID
```
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define pNode struct node*
struct node{
        char val;
        pNode lc;
        pNode rc;
        explicit node(char const &e):val(e),lc(nullptr),rc(nullptr){}
};

bool flag=true;

int get_h(pNode root);
pNode build();
pNode Build(int beg_in, int end_in, int beg_post, int end_post);
void pre_order(pNode root);
int find(const char str[],int beg,int end,char t);
bool is_equal(int beg_in,int end_in,int beg_post,int end_post);
void release(pNode root);

char post[27];
char in[27];

int main()
{
        scanf("%s",post);
        scanf("%s",in);
        pNode root=build();


        if(!flag){
                printf("INVALID\n");
                if(root){
                        release(root);
                }
        }else {
                printf("%d\n",get_h(root));
                pre_order(root);
                release(root);
        }

        return 0;

}
/*构建接口*/
pNode build()
{
        int end_in=strlen(in);
        int end_post=strlen(post);
        if(end_in!=end_post){
                flag= false;
                return nullptr;
        }
        return Build(0,end_in,0,end_post);
}
/*构建的核心*/
pNode Build(int beg_in, int end_in, int beg_post, int end_post)
{
        if(beg_in == end_in){return nullptr;}
        if(beg_post == end_post){return nullptr;}

        const char e=post[end_post - 1];
        pNode root=new node(e);


        /*
         * |----l_size---|
         * a b c d e f g h i j k l m n o p
         *                 ^
         *                 |
         *                 pos_root_in
         *
         * b a c e g f h d j k m o p n l i
         * ^               ^             ^ ^
         * |               |             | |
         * beg_post        post_l_last   e end_post
         *
         * 根据后序找到根(i)在中序中，根据根(i)分割序列为左子树与右子树，
         * 以pos_root_in为界，然后求出左侧的长度，从而在后序中，找到左子树
         * 的根节点(最后一个节点），分别左侧。右子树就是右侧，再递归右侧。
         *
         * */
        int pos_root_in=find(in, beg_in, end_in, e);

        int l_size= pos_root_in - beg_in;
        int post_l_last= beg_post + l_size;

        /*序列是否合法*/
        if(!is_equal(beg_in, pos_root_in, beg_post, post_l_last)){ flag= false;return nullptr;}

        /*注意边界条件*/
        root->lc=Build(beg_in, pos_root_in, beg_post, post_l_last);
        root->rc=Build(pos_root_in + 1, end_in, post_l_last, end_post - 1);

        return root;


}
/*先序*/
void pre_order(pNode root)
{
        if(!root) return;
        printf("%c",root->val);
        pre_order(root->lc);
        pre_order(root->rc);
}
/*高度*/
int get_h(pNode root)
{
        int h_l;
        int h_r;
        int max_h;
        if(root){
                h_l=get_h(root->lc);
                h_r=get_h(root->rc);
                max_h=std::max(h_l,h_r);
                return max_h+1;
        }else{
                /*空树定义为-1*/
                return -1;
        }
}

/*查找位置*/
int find(const char str[],int beg,int end,char t)
{
        int i;
        for(i=beg;i<end;i++){
                if(str[i]==t){
                        return i;
                }
        }
        return -1;
}

/*判断这两段序列是否相等*/
bool is_equal(int beg_in,int end_in,int beg_post,int end_post)
{
        int i,j;
        int plus_a=0;
        int product_a=1;
        int plus_b=0;
        int product_b=1;

        for(i=beg_in;i<end_in;i++){
                plus_a+=static_cast<int>(in[i]);
                product_a*=static_cast<int>(in[i]);
        }
        for(j=beg_post;j<end_post;j++){
                plus_b+=static_cast<int>(post[j]);
                product_b*=static_cast<int>(post[j]);
        }
        return ((plus_a == plus_b) && (product_a == product_b));
}
/*释放二叉树*/
void release(pNode root){
        if(root->lc){
                release(root->lc);
        }
        if(root->rc){
                release(root->rc);
        }
        delete root;
}

