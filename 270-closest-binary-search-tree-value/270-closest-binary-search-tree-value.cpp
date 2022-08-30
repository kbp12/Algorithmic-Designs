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
    double diff;
    int ans;
    int closestValue(TreeNode* root, double target) {
        int val, closest = root->val;
        while (root != nullptr) {
            val = root->val;
            closest = abs(val - target)<abs(closest - target) ? val : closest;
            root =  target < root->val ? root->left : root->right;
        }
        return closest;
    }
};