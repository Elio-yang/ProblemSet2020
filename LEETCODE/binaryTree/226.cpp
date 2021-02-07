/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */

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
        TreeNode* invertTree(TreeNode* root) {
                if(root==nullptr){return root;}
                TreeNode* tmp=root->right;
                root->right=root->left;
                root->left=tmp;
                invertTree(root->left);
                invertTree(root->right);
                return root;
        }

};

class Solution2 {
public:
        TreeNode* invertTree(TreeNode* root) {
                if(root==nullptr){return root;}
                invertTree(root->left);
                invertTree(root->right);
                TreeNode* tmp=root->right;
                root->right=root->left;
                root->left=tmp;
                return root;
        }

};

