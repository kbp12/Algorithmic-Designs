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
    TreeNode* buildtree(vector<int>& nums, int i, int j){
        if(i>j) return NULL;
        int m = i+(j-i)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildtree(nums,i,m-1);
        root->right = buildtree(nums,m+1,j);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        return buildtree(nums,i,j);
    }
};