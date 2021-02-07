/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */


#include <vector>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {}
};


class Solution {
public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
                if(root1==nullptr){return root2;}
                if(root2==nullptr){return root1;}
                root1->val+=root2->val;
                root1->left=mergeTrees(root1->left,root2->left);
                root1->right=mergeTrees(root1->right,root2->right);
                return root1;
        }
};