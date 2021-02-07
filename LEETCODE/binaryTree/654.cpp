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

        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {}
};

class Solution {
public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
                TreeNode *root=_build(nums,0,nums.size()-1);
                return root;
        }
        /*
        [s][][][][max][][][][][][e]
        |<-left->|root|<--right-->|
        */
        TreeNode* _build(vector<int>&nums,int s,int e){
                if(s>e){return nullptr;}
                int maxv=-1;
                int root_pos;
                for(int i=s;i<=e;i++){
                        if(nums[i]>maxv){
                                maxv=nums[i];
                                root_pos=i;
                        }
                }
                TreeNode* root=new TreeNode(maxv);
                root->left=_build(nums,s,root_pos-1);
                root->right=_build(nums,root_pos+1,e);
                return root;
        }
};