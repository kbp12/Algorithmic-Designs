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
    TreeNode* buildtree(int i, int j, vector<int>& nums){
        if(i>j) return NULL;
        int idx = i;
        for(int k=i+1;k<=j;k++){
            if(nums[k]>nums[idx]){idx = k;}
        }
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = buildtree(i,idx-1,nums);
        root->right = buildtree(idx+1,j,nums);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        return buildtree(i,j,nums);
    }
};