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
    string ans = "";
    string tree2str(TreeNode* root) {
        ans+=to_string(root->val);
        if(root->left and root->right){
            ans+="(";
            tree2str(root->left);
            ans+=")(";
            tree2str(root->right);
            ans+=")";
        }else if(root->left){
            ans+="(";
            tree2str(root->left);
            ans+=")";
        }else if(root->right){
            ans+="()(";
            tree2str(root->right);
            ans+=")";
        }
        return ans;
    }
};