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
    bool checkbst(TreeNode* root, long long low, long long high){
        if(!root) return true;
        if(low<root->val and root->val<high){
            return checkbst(root->left,low,root->val) and checkbst(root->right,root->val,high);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
       return checkbst(root,-1e18,1e18);
    }
};