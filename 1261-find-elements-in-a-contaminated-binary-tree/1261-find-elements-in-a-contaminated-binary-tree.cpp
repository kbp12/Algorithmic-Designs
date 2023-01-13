/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    set<int>s;
    void solve(TreeNode* root, int i){
        if(!root) return;
        s.insert(i);
        solve(root->left,2*i+1);
        solve(root->right,2*i+2);
    }
    FindElements(TreeNode* root){
        solve(root , 0);
    }
    bool find(int target) {
        return s.find(target) != s.end();   
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */