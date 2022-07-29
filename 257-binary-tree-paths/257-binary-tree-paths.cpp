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
    vector<string>ans;
    void findpath(TreeNode* root, string s){ 
        if(!root) return;
        if(s.size()){
            s+= "->";
        }
        string str = to_string(root->val);
        s+=str;
        if(!root->left and !root->right){
            ans.push_back(s);
            return;
        }
        findpath(root->left,s);
        findpath(root->right,s);
        return;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        findpath(root,"");
        return ans;
    }
};