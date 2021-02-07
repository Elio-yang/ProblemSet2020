/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/28
 */

#include <vector>
#include <stack>
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

class Solution {
public:
        vector<int> postorderTraversal(TreeNode *root)
        {
                vector<int> ans;
                _post_it(root,ans);
                return ans;

        }
        void _post(TreeNode *root,vector<int>&ans)
        {
                if (root){
                        _post(root->left,ans);
                        ans.push_back(root->val);
                        _post(root->right,ans);
                }
        }
        void _post_it(TreeNode *root,vector<int>&ans)
        {
                stack<TreeNode*>s;
                s.push(root);
                while (!s.empty()){
                        TreeNode *cur=s.top();
                        s.pop();
                        if (cur!= nullptr){
                                ans.push_back(cur->val);
                                s.push(cur->left);
                                s.push(cur->right);
                        }
                }
                reverse(ans.begin(),ans.end());
        }
        void _post_uni(TreeNode *root,vector<int>&ans)
        {
                stack<TreeNode*>s;
                if (root) s.push(root);
                while(!s.empty()){
                        TreeNode *cur=s.top();
                        if (cur){
                                s.pop();
                                s.push(cur);
                                s.push(nullptr);
                                if (cur->right) s.push(cur->right);
                                if (cur->left) s.push(cur->left);
                        }else{
                                s.pop();
                                cur=s.top();
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