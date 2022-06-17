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
    int ans = 0;
    int findpath(TreeNode* root){
        if(root==NULL) return 0;
        int l = findpath(root->left);
        int r = findpath(root->right);
        if(root->left && root->right){
            if(root->left->val==root->val && root->right->val==root->val){
                int p = l+r+1;
                ans = max(ans,p);
                return 1+max(l,r);
            }else if(root->left->val==root->val){
                int p = l+1;
                ans = max(ans,p);
                return p;
            }else if(root->right->val==root->val){
                int p = r+1;
                ans = max(ans,p);
                return p;
            }
        }else if(root->left){
            if(root->left->val==root->val){
                int p = l+1;
                ans = max(ans,p);
                return p;
            }
        }else if(root->right){
            if(root->right->val==root->val){
                int p = r+1;
                ans = max(ans,p);
                return p;
            }
        }
        return 1;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        findpath(root);
        if(ans==0) return 0;
        return ans-1;
    }
};