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
        TreeNode() : val(0), left(nullptr), right(nullptr)
        {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr)
        {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
        {}
};

class Solution {
public:
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                vector<int>path;
                vector<vector<int>>ans;
                if(root==nullptr){
                        return ans;
                }
                getPath(root,path,ans,targetSum);
                return ans;
        }
        void getPath(TreeNode*root,vector<int>&path,vector<vector<int>>&ans,int targetSum)
        {
                path.push_back(root->val);
                if(!root->left&&!root->right){
                        int sum=0;
                        for(auto i:path){
                                sum+=i;
                        }
                        if(sum==targetSum){
                                ans.push_back(path);
                        }
                        return;
                }
                if(root->left){
                        getPath(root->left,path,ans,targetSum);
                        path.pop_back();
                }
                if(root->right){
                        getPath(root->right,path,ans,targetSum);
                        path.pop_back();
                }
        }
};