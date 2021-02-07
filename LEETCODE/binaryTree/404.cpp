/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */


#include <algorithm>
#include <queue>
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
        int sumOfLeftLeaves(TreeNode* root) {
                int ans=0;
                if(root==nullptr){return 0;}
                queue<TreeNode*>q;
                q.push(root);
                while(!q.empty()){
                        int size = q.size();
                        for(int i=0;i<size;i++){
                                TreeNode* cur=q.front();
                                q.pop();
                                if(has_left_leaf_child(cur)){ans+=cur->left->val;}
                                if(cur->left){q.push(cur->left);}
                                if(cur->right){q.push(cur->right);}
                        }
                }
                return ans;
        }
        inline bool has_left_leaf_child(TreeNode*root){
                return root->left!=nullptr&&root->left->left==nullptr&&root->left->right==nullptr;
        }
};