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
        bool flag=false;
        bool hasPathSum(TreeNode* root, int targetSum) {
                if(root==nullptr){return false;}
                return getPath(root,targetSum-root->val);

        }
        bool getPath(TreeNode*root,int cnt)
        {
                if(root->left==nullptr&&root->right==nullptr){
                        return cnt==0;
                }
                if(root->left){
                        cnt-=root->left->val;
                        if(getPath(root->left,cnt)){return true;}
                        cnt+=root->left->val;
                }
                if(root->right){
                        cnt-=root->right->val;
                        if(getPath(root->right,cnt)){return true;}
                        cnt+=root->right->val;
                }
                return false;
        }
};

class Solution2 {
public:
        bool flag=false;
        bool hasPathSum(TreeNode* root, int targetSum) {
                if(root==nullptr){return false;}
                vector<int>path;
                getPath(root,path,targetSum);
                return flag;

        }
        void getPath(TreeNode*root,vector<int>&path,int sum)
        {
                path.push_back(root->val);
                if(root->left==nullptr&&root->right==nullptr){
                        int ans=0;
                        for(auto i:path){
                                ans+=i;
                        }
                        if(ans==sum){
                                flag=true;
                        }
                        return;
                }
                if(root->left){
                        getPath(root->left,path,sum);
                        path.pop_back();
                }
                if(root->right){
                        getPath(root->right,path,sum);
                        path.pop_back();
                }
        }
};