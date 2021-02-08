/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/8
 */


#include <vector>
#include <cstring>
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
        int i=0;
        int vals[10005];
        TreeNode* convertBST(TreeNode* root) {
                vector<int>seq;
                mid(root,seq);
                memset(vals,0x3f,sizeof(vals));
                int size=seq.size();
                int cur_max=0;
                for(int j= size - 1; j >= 0; j--){
                        cur_max+=seq[j];
                        if(vals[j] == 0x3f3f3f3f){
                                vals[j]=cur_max;
                        }
                }
                rebuild(root);
                return root;
        }
        void mid(TreeNode*root,vector<int>&seq)
        {
                if(root==nullptr){return;}
                if(root->left){
                        mid(root->left,seq);
                }
                seq.push_back(root->val);
                if(root->right){
                        mid(root->right,seq);
                }
        }
        void rebuild(TreeNode*root){
                if(root==nullptr){return;}
                if(root->left){
                        rebuild(root->left);
                }
                root->val=vals[i++];
                if(root->right){
                        rebuild(root->right);
                }
        }
};

/*上述操作可以在一次递归内完成*/


class Solution2 {
public:
        int pre=0;
        TreeNode* convertBST(TreeNode* root) {
                mid(root);
                return root;
        }
        void mid(TreeNode* cur){
                if(cur== nullptr){return;}
                mid(cur->right);
                //mid node
                cur->val+=pre;
                pre=cur->val;
                mid(cur->right);
        }

};