/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/29
 */



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
        int maxDepth(TreeNode* root) {
                if(root==nullptr){return 0;}
                else{
                        return 1+max(maxDepth(root->left),maxDepth(root->right));
                }
        }
};

class Solution {
public:
        int maxD=0;
        int maxDepth(TreeNode* root) {
                if(root==nullptr){return 0;}
                else{
                        dfs(root,1);
                }
                return maxD;
        }
        void dfs(TreeNode *root,int level)
        {
                if(root==nullptr){return;}
                if(level>maxD){maxD=level;}
                dfs(root->left,level+1);
                dfs(root->right,level+1);
        }
};