/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    bool dfs(Node* root, Node* temp){
        if(root==nullptr) return false;
        if(root==temp) return true;
        return dfs(root->left,temp) or dfs(root->right,temp);
    }
    
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(dfs(p,q)) return p;
        if(dfs(q,p)) return q;
        set<Node*>s;
        Node* temp = p->parent;
        while(temp){
            s.insert(temp);
            temp = temp->parent;
        }
        while(q){
            if(s.find(q)!=s.end()) return q;
            q = q->parent;
        }
        return nullptr;
    }
};