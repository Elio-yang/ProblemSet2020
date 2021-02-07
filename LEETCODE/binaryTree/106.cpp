/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */

#include <cstdio>
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
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
        {
                int size_i = inorder.size();
                int size_p = postorder.size();
                TreeNode *root = _build(inorder, postorder, 0, size_i - 1, 0, size_p - 1);
                return root;
        }

        TreeNode *_build(vector<int> &inorder, vector<int> &postorder, int i_s, int i_e, int p_s, int p_e)
        {
                if (i_s > i_e) { return nullptr; }
                if (p_s > p_e) { return nullptr; }
                int root_val = postorder[p_e];
                int root_pos;
                for (int i = i_s; i <= i_e; i++) {
                        if (inorder[i] == root_val) {
                                root_pos = i;
                                break;
                        }
                }
                TreeNode *root = new TreeNode(root_val);
                int left_num = root_pos - i_s;
                root->left = _build(inorder, postorder, i_s, root_pos - 1, p_s, p_s + left_num - 1);
                root->right = _build(inorder, postorder, root_pos + 1, i_e, p_s + left_num, p_e - 1);
                return root;
        }
};