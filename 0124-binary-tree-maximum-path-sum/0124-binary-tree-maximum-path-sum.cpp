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
    int maxSum(TreeNode* root,int &sum){
        if(root==NULL) return 0;
        int Lsum=max(maxSum(root->left,sum),0);
        int Rsum=max(maxSum(root->right,sum),0);
        int currSum=root->val+Rsum+Lsum;
        sum=max(sum,currSum);
        return max(root->val+Rsum,root->val+Lsum);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        maxSum(root,sum);
        return sum;
    }
};