/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/28
 */

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
        vector<int> inorderTraversal(TreeNode *root)
        {
                vector<int> ans;
                _in_it(root,ans);
                return ans;

        }
        void _in_it(TreeNode *root,vector<int>&ans)
        {
                stack<TreeNode*>s;
                TreeNode *cur=root;
                while (cur!= nullptr||!s.empty()){
                        if(cur!=nullptr){
                                s.push(cur);
                                cur=cur->left;
                        }else{
                                TreeNode *leftest=s.top();
                                ans.push_back(leftest->val);
                                s.pop();
                                cur=leftest->right;
                        }
                }
        }
        void _in_uni(TreeNode *root,vector<int>&ans)
        {
                stack<TreeNode*>s;
                if (root) s.push(root);
                while (!s.empty()){
                        TreeNode *cur=s.top();
                        if (cur){
                                s.pop();
                                if (cur->right) s.push(cur->right);
                                s.push(cur);
                                s.push(nullptr);
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