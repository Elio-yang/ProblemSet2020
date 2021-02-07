
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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder, int beg_pre, int end_pre, int beg_in, int end_in);

void pre_order(TreeNode *root);

int main()
{
        vector<int> pre = {4, 3, 1, 2};
        vector<int> in = {1, 2, 3, 4};
        TreeNode *root = buildTree(pre, in);
        pre_order(root);

        return 0;


}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{

        return _buildTree(preorder, inorder,
                          0, preorder.size() - 1, 0, inorder.size() - 1);

}

TreeNode *_buildTree(vector<int> &preorder, vector<int> &inorder,
                     int beg_pre, int end_pre, int beg_in, int end_in)
{
        if (beg_pre > end_pre) { return nullptr; }
        if (beg_in > end_in) { return nullptr; }

        TreeNode *root = new TreeNode(preorder[beg_pre]);
        int pos_root = 0;
        for (int i = beg_in; i <= end_in; i++) {
                if (inorder[i] == preorder[beg_pre]) {
                        pos_root = i;
                        break;
                }
        }
        int left_num = pos_root - beg_in;

        root->left = _buildTree(preorder, inorder,
                                beg_pre + 1, beg_pre + left_num, beg_in, pos_root-1);
        root->right = _buildTree(preorder, inorder,
                                 beg_pre + left_num+1 , end_pre, pos_root+1 , end_in);
        return root;
}

void pre_order(TreeNode *root)
{
        if (root != nullptr) {
                printf("%d ", root->val);
                pre_order(root->left);
                pre_order(root->right);
        }
}