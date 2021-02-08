/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/2/8
 */
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>

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

        void tra(TreeNode*root,unordered_map<int,int>&Map){
                if(root->left){
                        tra(root->left,Map);
                }
                Map[root->val]++;
                if(root->right){
                        tra(root->right,Map);
                }
        }
        bool static cmp(pair<int,int>a,pair<int,int>b){
                return a.second>b.second;
        }
        vector<int> findMode(TreeNode* root) {
                unordered_map<int,int> Map;
                vector<int>ans;
                if(root==NULL){return ans;}
                tra(root,Map);
                vector<pair<int,int>> vec(Map.begin(),Map.end());
                sort(vec.begin(),vec.end(),cmp);
                ans.push_back(vec[0].first);
                for(int i=1;i<vec.size();i++){
                        if(vec[i].second==vec[0].second){
                                ans.push_back(vec[i].first);
                        }
                        else break;
                }
                return ans;
        }
};



class Solution2 {
public:
        int cnt=0;
        TreeNode* pre=NULL;
        int maxCnt=INT_MIN;
        vector<int> ans;
        vector<int> findMode(TreeNode* root) {
                mid(root);
                return ans;
        }
        void mid(TreeNode*cur)
        {
                if(!cur){return ;}
                mid(cur->left);
                //mid node
                if(pre==NULL){
                        cnt=1;
                }
                else if(pre->val==cur->val){
                        cnt++;
                }
                else{
                        cnt=1;
                }

                if(cnt==maxCnt){
                        ans.push_back(cur->val);
                }
                if(cnt>maxCnt){
                        maxCnt=cnt;
                        ans.clear();
                        ans.push_back(cur->val);
                }
                pre=cur;//update node
                mid(cur->right);
        }
};

