/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */
#include <algorithm>

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


/*找到最后一层最左边的值*/
class Solution {
public:
        int l = 0;
        int ans;
        bool flag = 0;

        int findBottomLeftValue(TreeNode *root)
        {
                if (root->left == nullptr && root->right == nullptr) { return root->val; }
                l = geth(root);
                dfs(root, 1);
                return ans;
        }

        void dfs(TreeNode *root, int level)
        {
                if (flag == 1) { return; }
                if (root == nullptr) { return; }
                if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
                        if (level + 1 == l) {
                                flag = 1;
                                ans = root->left->val;
                                return;
                        }
                } else if (root->right && root->right->left == nullptr && root->right->right == nullptr) {
                        if (level + 1 == l) {
                                flag = 1;
                                ans = root->right->val;
                                return;
                        }
                }
                dfs(root->left, level + 1);
                dfs(root->right, level + 1);
        }

        int geth(TreeNode *root)
        {
                if (root == nullptr) { return 0; }
                return 1 + max(geth(root->left), geth(root->right));
        }

};