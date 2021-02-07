/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/29
 */
#include <vector>

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
        bool isSymmetric(TreeNode *root)
        {
                if (root == nullptr) { return true; }
                return comp(root->left, root->right);
        }

        bool comp(TreeNode *left_t, TreeNode *right_t)
        {
                if (left_t == nullptr && right_t != nullptr) { return false; }
                else if (right_t == nullptr && left_t != nullptr) { return false; }
                else if (left_t == nullptr && right_t == nullptr) { return true; }
                else if (left_t->val != right_t->val) { return false; }
                else {
                        bool out_cmp = comp(left_t->left, right_t->right);
                        bool in_cmp = comp(left_t->right, right_t->left);
                        return out_cmp & in_cmp;
                }
        }
};

class Solution2 {
public:
        bool isSymmetric(TreeNode* root) {
                if(root==nullptr){return true;}
                queue<TreeNode*>q;
                q.push(root->left);
                q.push(root->right);
                while(!q.empty()){
                        TreeNode *left_n=q.front();
                        q.pop();
                        TreeNode *right_n=q.front();
                        q.pop();
                        if(left_n==nullptr && right_n==nullptr){continue;}
                        if(left_n==nullptr||right_n==nullptr||(left_n->val!=right_n->val)){return false;}
                        q.push(left_n->left);
                        q.push(right_n->right);
                        q.push(left_n->right);
                        q.push(right_n->left);
                }
                return true;
        }
};


int main()
{
        return 0;
}