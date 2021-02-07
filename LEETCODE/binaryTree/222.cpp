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
        int countNodes(TreeNode* root) {
                return getNodes(root);
        }
        int getNodes(TreeNode* root){
                if(root==nullptr){return 0;}
                int left_n=getNodes(root->left);
                int right_n=getNodes(root->right);
                return 1+left_n+right_n;
        }
};

class Solution2 {
public:
        int countNodes(TreeNode* root) {
                if(root==nullptr){return 0;}
                queue<TreeNode*> q;
                q.push(root);
                int nums=0;
                while(!q.empty()){
                        int size=q.size();
                        for(int i=0;i<size;i++){
                                nums++;
                                TreeNode* cur=q.front();
                                q.pop();
                                if(cur->left){q.push(cur->left);}
                                if(cur->right){q.push(cur->right);}
                        }
                }
                return nums;
        }
};
int main()
{
        return 0;
}
