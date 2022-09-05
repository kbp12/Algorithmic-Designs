/*
// Definition for a Node.
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
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int sz = q.size();
            vector<int>order;
            while(sz--){
                Node* f = q.front(); q.pop();
                order.push_back(f->val);
                int sz2 = f->children.size();
                for(int i=0;i<sz2;i++){
                    q.push(f->children[i]);
                }
            }
            ans.push_back(order);
        }
        return ans;
    }
};