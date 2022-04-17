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
    TreeNode* prev = NULL;
    TreeNode* toreturn = NULL;
    void transform(TreeNode* root){
        if(!root) return;
        transform(root->left);
        
        if(prev!=NULL){
            prev->left = NULL;
            prev->right = root;
            prev = root;
        }else{
            prev = root;
            toreturn = root;
        }
        
        transform(root->right);
        return;
        
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        transform(root);
        prev->left = NULL;
        prev->right = NULL;
        return toreturn;
    }
};