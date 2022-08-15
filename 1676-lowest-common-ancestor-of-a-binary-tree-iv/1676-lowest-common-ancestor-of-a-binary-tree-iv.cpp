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
class Solution {
public:
    int n,count;
    unordered_set<TreeNode*>s;
    TreeNode* ans;
    int lca(TreeNode* root){
        if(root==nullptr) return 0;
        int l = lca(root->left);
        int r = lca(root->right);
        l+=r;
        if(s.find(root)!=s.end()) l++;
        if(l==n){
            if(ans==nullptr){
                ans = root;
            }
        }
        return l;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        count = 0;
        n = nodes.size();
        ans = nullptr;
        for(int i=0;i<n;i++){
            s.insert(nodes[i]);
        }
        lca(root);
        return ans;
        
    }
};