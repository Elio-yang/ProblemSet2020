//
// Created by ELIO on 2020/12/3.
//

#include <iostream>
#include <cstdio>
#include <string>
#include "../../My_stl.h"
using namespace std;
#define T int


class node {
public:
        int layer;
        T data;
        int sum;
        node *father;
        node *lchild;
        node *rchild;

        explicit node(T d) : layer(0), data(d), father(nullptr), lchild(nullptr), rchild(nullptr)
        {}
};

vector<node*>ans;

class Tree {
        /*简单二叉树的模板*/
public:
        node *root;

        Tree() : root(nullptr)
        {}

        node *pre_creat()
        {
                T val;
                std::cin >> val;
                if (val == 0) { return nullptr; }
                node *new_node = new node(val);
                new_node->lchild = pre_creat();
                new_node->rchild = pre_creat();
                return new_node;
        }
        node *pre_creat_fa(node*proot,node*fa/*,int sum*/)
        {
                T val;
                std::cin>>val;
                if (val==0){return nullptr;}

                node* father_node=fa;
                node* new_node=new node(val);
                /*new_node->sum=sum+father_node->sum*/
                new_node->father=father_node;
                new_node->lchild=pre_creat_fa(new_node->lchild,new_node);
                new_node->rchild=pre_creat_fa(new_node->rchild,new_node);
                return new_node;
        }
        node *lc_rb_pre_creat(node* proot,int sum)
        {
                T val;
                std::cin>>val;
                if (val== 0){return nullptr;}
                node *new_node=new node(val);
                new_node->father=proot;
                new_node->sum=sum+new_node->data;
                new_node->lchild=lc_rb_pre_creat(new_node,new_node->sum);
                if (proot== nullptr){new_node->rchild=lc_rb_pre_creat(new_node,0);}
                else{new_node->rchild=lc_rb_pre_creat(new_node,new_node->sum);}
                return new_node;
        }
        node *lc_rb_pre_creat(node*proot)
        {
                T val;
                std::cin>>val;
                if (val== 0){return nullptr;}
                node *new_node=new node(val);
                new_node->father=proot;
                new_node->lchild=lc_rb_pre_creat(new_node);
                new_node->rchild=lc_rb_pre_creat(new_node->father);
                return new_node;
        }

        int get_height(node *&proot)
        {
                if (proot == nullptr) { return -1; }
                int h_l = get_height(proot->lchild);
                int h_r = get_height(proot->rchild);
                return 1 + max(h_l, h_r);
        }

        void pre_order(node *proot)
        {
                if (proot == nullptr) { return; }
                std::cout << proot->data << " ";
                pre_order(proot->lchild);
                pre_order(proot->rchild);
        }

        void in_order(node *proot)
        {
                if (proot == nullptr) { return; }
                in_order(proot->lchild);
                std::cout << proot->data << " ";
                in_order(proot->rchild);
        }

        void post_order(node *proot)
        {
                if (proot== nullptr){return;}
                post_order(proot->lchild);
                post_order(proot->rchild);
                std::cout<<proot->data<<" ";
        }
        void level_order(node *proot)
        {
                queue<node*> q;
                q.push(proot);
                while (!q.empty()){
                        node *tmp=q.front();
                        q.pop();
                        std::cout<<tmp->data<<" ";
                        if (tmp->lchild){q.push(tmp->lchild);}
                        if (tmp->rchild){q.push(tmp->rchild);}
                }
        }
        void find_dfs(int k,node*proot){
                if (proot->lchild== nullptr&&proot->rchild== nullptr){
                        if (proot->sum==k){
                                ans.push_back(proot);
                        }
                }
                if (proot->lchild!= nullptr){
                        find_dfs(k,proot->lchild);
                }
                if (proot->rchild!= nullptr){
                        find_dfs(k,proot->rchild);
                }
                /*查找时候注意边界的问题，与遍历稍有区别*/
        }

        char* post;//[postl,postr]--->[0,strlen-1]
        char* in;
        node* in_post_create(int postl,int postr,int inl,int inr)
        {
                /*
                        [postL,postL+N-1] [postL+N,postR-1] [postR]
                        [inL, k-1][k][k+1,inR]
                 */
                if (postl==postr){return nullptr;}
                if (inl==inr){return nullptr;}

                node* proot=new node(post[postr]);
                int i;
                for ( i = inl; i <=inr ; i++) {
                        if (in[i]==post[postr]){
                                break;
                        }
                }
                int N=i-inl;//左子树节点数
                /*
                 * 判断是否合法
                 *  [postL,postL+N-1] [inL, k-1] 包含的是否一样
                 *   [k+1,inR] [postL+N,postR-1] 包含的是否一样
                 *
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
                        if(!is_equal(beg_in, pos_root_in, beg_post, post_l_last)){ flag= false;return nullptr;}
                 *
                 * */
                proot->lchild=in_post_create(postl,postl+N-1,inl,i-1);
                proot->rchild=in_post_create(postl+N,postr-1,i+1,inr);
                return proot;
        }
        char* pre;
        node*pre_in_creat(int prel,int prer,int inl,int inr)
        {
                if (prel==prer){return nullptr;}
                if (inl==inr){return nullptr;}
                node* proot=new node(pre[prel]);
                int i;
                for (int i = inl; i <=inr ; i++) {
                        if (in[i]==pre[prel]){
                                break;
                        }
                }
                int N=i-inl;
                /*
                        [inl,k-1][k][k+1,inr]
                        [prel][prel+1,prel+N][prel+N+1,prer]
                 */
                /*判断是否合法*/
                proot->lchild=pre_in_creat(prel+1,prel+N,inl,i-1);
                proot->rchild=pre_in_creat(prel+N+1,prer,i+1,inr);
                return proot;

        }

        vector<int>path;
        vector<string>Spath;
        void all_path(node*proot)
        {
                path.push_back(proot->data);
                if (proot->lchild== nullptr&&proot->rchild== nullptr){
                        string spath;
                        for (int i = 0; i < path.size()-1; i++) {
                                spath+=to_string(path[i]);
                                spath+="->";
                        }
                        /*"->的处理*/
                        spath+=to_string(path[path.size()-1]);
                        Spath.push_back(spath);
                        return;
                }
                if (proot->lchild){
                        all_path(proot->lchild);
                        path.pop_back();
                }
                if (proot->rchild){
                        all_path(proot->rchild);
                        path.pop_back();
                }
        }
        /*
         vector<string> binaryTreePaths(TreeNode* root) {
                 vector<string> result;
                 vector<int> path;
                 if (root == NULL) return result;
                 traversal(root, path, result);
                 return result;
         }
         */
};

int main()
{
        Tree binTree;
        binTree.root = binTree.pre_creat_fa(binTree.root, nullptr);

        binTree.pre_order(binTree.root);
        std::cout << std::endl;

        binTree.level_order(binTree.root);
        std::cout<<std::endl;

        std::cout << "height=" << binTree.get_height(binTree.root);
        std::cout<<std::endl;

        node* tmp=binTree.root;
        while (tmp->lchild!= nullptr){
                tmp=tmp->lchild;
        }
        node *fa=tmp;
        while (fa!= nullptr){
                printf("%d ",fa->data);
                fa=fa->father;
        }
        return 0;
}
/*
 1 3 5 4 0 0 0 2 0 0 6 8 0 0 9 7 0 0 0
 */