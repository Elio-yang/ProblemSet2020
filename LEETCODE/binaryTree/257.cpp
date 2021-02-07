/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/7
 */

#include <string>
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



/*回溯：
 * 1.递归函数 参数 返回值
 * 2.确定终止条件
 * 3.确定单层逻辑
 * */
class Solution {
public:
        vector<string> binaryTreePaths(TreeNode* root) {
                vector<int>path;
                vector<string>ans;
                if(root==nullptr){return ans;}
                getpath(root,path,ans);
                return ans;
        }
        void getpath(TreeNode*root,vector<int>&path,vector<string>&ans)
        {
                path.push_back(root->val);
                if(root->left==nullptr&&root->right==nullptr){
                        /*到叶节点终止递归，打印路径*/
                        string aPath;
                        for(int i=0;i<path.size()-1;i++){
                                aPath+=to_string(path[i]);
                                aPath+="->";
                        }
                        aPath+=to_string(path[path.size()-1]);
                        ans.push_back(aPath);
                        return;
                }
                /*
                 * 回溯和递归是一一对应的，有一个递归，就要有一个回溯
                 */
                if(root->left){
                        getpath(root->left,path,ans);
                        path.pop_back();//回溯
                }
                if(root->right){
                        getpath(root->right,path,ans);
                        path.pop_back();//回溯
                }
        }
};