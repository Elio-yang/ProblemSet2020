/*
 * @author Elio Yang
 * @email  jluelioyang2001@gamil.com
 * @date 2021/1/28
 */

#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
        vector<vector<int>> levelOrder(Node* root) {
                vector<vector<int>>ans;
                queue<Node*>q;
                if (root){q.push(root);}
                while (!q.empty()){
                        vector<int> ansi;
                        int size=q.size();
                        for (int i = 0; i < size; i++) {
                                Node *cur=q.front();
                                q.pop();
                                ansi.push_back(cur->val);
                                int sizei=cur->children.size();
                                for (int j = 0; j < sizei; j++) {
                                        q.push(cur->children[j]);
                                }
                        }
                        ans.push_back(ansi);
                }
                return ans;
        }
};