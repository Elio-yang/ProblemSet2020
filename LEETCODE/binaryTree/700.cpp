/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {}
};


class Solution {
public:
        TreeNode*ans;
        TreeNode* searchBST(TreeNode* root, int val) {
                search(root,val);
                return ans;
        }
        void search(TreeNode* root, int val) {
                if(root==nullptr){return ;}
                if(root->val==val){ans=root;}
                if(val> root->val){searchBST(root->right,val);}
                if(val<root->val){searchBST(root->left,val);}
        }
};