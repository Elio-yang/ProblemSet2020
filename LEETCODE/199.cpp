/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/28
 */

#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
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
        vector<int> rightSideView(TreeNode* root) {
                vector<int> ans;
                queue<TreeNode*> q;
                if(root){q.push(root);}
                while(!q.empty()){
                        int size=q.size();
                        for(int i=0;i<size;i++){
                                TreeNode *cur=q.front();
                                q.pop();
                                if(i==size-1){
                                        ans.push_back(cur->val);
                                }
                                if(cur->left){q.push(cur->left);}
                                if(cur->right){q.push(cur->right);}
                        }
                }
                return ans;
        }
};
