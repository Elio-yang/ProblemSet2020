/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/6
 */
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
        int minDepth(TreeNode* root) {
                int level=0;
                if(root==nullptr){return 0;}
                queue<TreeNode*>q;
                q.push(root);
                while(!q.empty()){
                        int size=q.size();
                        level++;
                        for(int i=0;i<size;i++){
                                TreeNode *cur=q.front();
                                q.pop();
                                if(isleaf(cur)){return level;}
                                if(cur->left){q.push(cur->left);}
                                if(cur->right){q.push(cur->right);}
                        }
                }
                return level;
        }
        bool isleaf(TreeNode *node){
                return node->left==nullptr&&node->right==nullptr;
        }
};
class Solution2 {
public:
        /*注意初始值*/
        int d=0x3f3f3f3f;
        int minDepth(TreeNode* root) {
                if(root==nullptr){return 0;}
                dfs(root,0);
                return d+1;
        }
        void dfs(TreeNode* root,int level){
                if(root==nullptr){return;}
                if(isleaf(root)){d=min(level,d);}
                dfs(root->left,level+1);
                dfs(root->right,level+1);
        }
        bool isleaf(TreeNode *node){
                return node->left==nullptr&&node->right==nullptr;
        }
};

class Solution3 {
public:
        int minDepth(TreeNode* root) {
                return getdepth(root);
        }
        int getdepth(TreeNode *root){
                if(root==nullptr){return 0;}
                int dep_l=getdepth(root->left);
                int dep_r=getdepth(root->right);
                /*最小深度！！*/
                if(!root->left&&root->right){
                        return 1+dep_r;
                }
                if(!root->right&&root->left){
                        return 1+dep_l;
                }
                return 1+min(dep_l,dep_r);
        }

};
int main()
{
        return 0;
}
