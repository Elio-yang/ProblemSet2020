/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */

#include <stdio.h>
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
        bool isValidBST(TreeNode* root) {
                vector<int>seq;
                in_order(root,seq);
                int size=seq.size();
                for(int i=0;i<size-1;i++){
                        if(seq[i]>=seq[i+1]){
                                return false;
                        }
                }
                return true;
        }
        void in_order(TreeNode*root,vector<int>&seq){
                if(root->left){in_order(root->left,seq);}
                seq.push_back(root->val);
                if(root->right){in_order(root->right,seq);}
        }
};