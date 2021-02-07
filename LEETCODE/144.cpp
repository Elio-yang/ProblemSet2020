/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/22
 */
#include <vector>
#include <stack>
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
        vector<int> preorderTraversal(TreeNode *root)
        {
                vector<int> ans;
                _pre_recur(root, ans);
                return ans;

        }
        void _pre_recur(TreeNode *root, vector<int>&ans)
        {
                if (root== nullptr){return;}
                ans.push_back(root->val);
                _pre_recur(root->left, ans);
                _pre_recur(root->right, ans);
        }
        void _pre_it(TreeNode *root, vector<int>&ans)
        {
                stack<TreeNode*> s;
                s.push(root);
                while (!s.empty()){
                        TreeNode *cur=s.top();
                        s.pop();
                        if (cur!= nullptr){
                                ans.push_back(cur->val);
                                s.push(cur->right);
                                s.push(cur->left);
                        }
                }
        }
        void _pre_uni(TreeNode *root,vector<int>&ans)
        {
                stack<TreeNode *> s;
                if (root) s.push(root);
                while (!s.empty()) {
                        TreeNode *cur = s.top();
                        if (cur) {
                                s.pop();
                                if (cur->right) s.push(cur->right);
                                if (cur->left) s.push(cur->left);
                                s.push(cur);
                                s.push(nullptr);
                        } else {
                                s.pop();
                                cur = s.top();
                                s.pop();
                                ans.push_back(cur->val);
                        }
                }
        }

};
int main()
{
        return 0;
}