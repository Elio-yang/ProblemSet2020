//
// Created by ELIO on 2020/11/8.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define pNode struct node*
struct node{
        char val;
        pNode lc;
        pNode rc;

        node(char const &e):val(e),lc(NULL),rc(NULL){}
};

bool flag=true;

int get_h(pNode root);
pNode build(char in[],char post[]);
pNode Build(int in_beg,int in_end,int post_beg,int post_end);
void pre_order(pNode root);
int find(char str[],int beg,int end,char t);
bool is_equal(int beg_in,int end_in,int beg_post,int end_post);
void relase(pNode root);

char post[27];
char in[27];

int main()
{
        scanf("%s",post);
        scanf("%s",in);

        pNode root=build(in,post);

        if(!flag){
                printf("INVALID\n");
        }else {
                pre_order(root);
        }

        return 0;

}

pNode build(char in[],char post[])
{
        int end_in=strlen(in);
        int end_post=strlen(post);
        return Build(0,end_in,0,end_post);
}

pNode Build(int in_beg,int in_end,int post_beg,int post_end)
{
        if(in_beg==in_end){return nullptr;}
        if(post_beg==post_end){return nullptr;}

        const char e=post[post_end-1];
        pNode root=new node(e);


/*
 * |----l_size---|
 * a b c d e f g h i j k l m n o p
 *                 ^
 *                 |
 *                 pos_in_root
 *
 * b a c e g f h d j k m o p n l i
 * ^               ^             ^ ^
 * |               |             | |
 * post_beg        post_l_last      e post_end
 * */
        int pos_in_root=find(in,in_beg,in_end,e);

        int l_size=pos_in_root-in_beg;
        int post_l_last=post_beg+l_size;
        if(!is_equal(in_beg,pos_in_root,post_beg,post_l_last)){flag= false;return NULL;}

        root->lc=Build(in_beg,pos_in_root,post_beg,post_l_last);
        root->rc=Build(pos_in_root+1,in_end,post_l_last,post_end-1);

        return root;


}
void pre_order(pNode root)
{
        if(!root) return;
        printf("%c",root->val);
        pre_order(root->lc);
        pre_order(root->rc);
}
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
                 return 0;
         }
}
int find(char str[],int beg,int end,char t)
{
        int i;
        for(i=beg;i<end;i++){
                if(str[i]==t){
                        return i;
                }
        }
        return -1;
}

bool is_equal(int beg_in,int end_in,int beg_post,int end_post)
{
        int i;
        int j;
        int plus1=0;
        int product1=1;
        int plus2=0;
        int product2=1;
        for(i=beg_in;i<end_in;i++){
                plus1+=(int)in[i];
                product1*=(int)in[i];
        }
        for(j=beg_post;j<end_post;j++){
                plus2+=(int)post[j];
                product2*=(int)post[j];
        }
        return ((plus1==plus2)&&(product1==product2));
}
