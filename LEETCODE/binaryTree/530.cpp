/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/8
 */

#include <vector>
#include <limits.h>
#include <cmath>



/*for a BST inorder is very important */
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
        int getMinimumDifference(TreeNode *root)
        {
                vector<int> seq;
                in_order(root, seq);
                int Min = INT_MAX;
                for (int i = 0; i < seq.size() - 1; i++) {
                        if (abs(seq[i] - seq[i + 1]) < Min) {
                                Min = abs(seq[i] - seq[i + 1]);
                        }
                }
                return Min;
        }

        void in_order(TreeNode *root, vector<int> &seq)
        {
                if (root->left) {
                        in_order(root->left, seq);
                }
                seq.push_back(root->val);
                if (root->right) {
                        in_order(root->right, seq);
                }
        }

};


/*record pointer when doing recursion */
class Solution2 {
public:
        int result=INT_MAX;
        TreeNode* pre;
        int getMinimumDifference(TreeNode* root) {
                in_order(root);
                return result;
        }
        void in_order(TreeNode*cur){
                if(!cur){return ;}
                in_order(cur->left);
                if(pre){
                        result=min(result,abs(pre->val-cur->val));
                }
                pre=cur;
                in_order(cur->right);
        }
};