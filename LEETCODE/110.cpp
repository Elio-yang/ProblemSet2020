/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/6
 */
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr)
        {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
        {}
};


class Solution {
public:
        bool isBalanced(TreeNode* root) {
                if(root==nullptr){return true;}
                queue<TreeNode*>q;
                q.push(root);
                while(!q.empty()){
                        int size=q.size();
                        for(int i=0;i<size;i++){
                                TreeNode *cur=q.front();
                                int h_l=geth(cur->left);
                                int h_r=geth(cur->right);
                                if(abs(h_l-h_r)>1){return false;}
                                q.pop();
                                if(cur->left){q.push(cur->left);}
                                if(cur->right){q.push(cur->right);}
                        }
                }
                return true;
        }
        int geth(TreeNode* root){
                if(root==nullptr){return 0;}
                else return 1+max(geth(root->left),geth(root->right));
        }
};

class Solution2 {
public:
        bool isBalanced(TreeNode* root) {
                return geth(root)==-1?false:true;
        }
        int geth(TreeNode* root){
                if(root==nullptr){return 0;}
                int dep_l=geth(root->left);
                if(dep_l==-1){return -1;}
                int dep_r=geth(root->right);
                if(dep_r==-1){return -1;}
                return abs(dep_l-dep_r)>1?-1:1+max(dep_r,dep_l);
        }
};
