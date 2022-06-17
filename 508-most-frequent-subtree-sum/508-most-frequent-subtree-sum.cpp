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
    unordered_map<int,int>mpp;
    int bfs(TreeNode* root){
        if(root==NULL) return 0;
        int sum = bfs(root->left)+bfs(root->right)+root->val;
        mpp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        bfs(root);
        int maxcount = 0;
        for(auto it:mpp){
            if(it.second>maxcount) maxcount = it.second;
        }
        vector<int>ans;
        for(auto it:mpp){
            if(it.second==maxcount){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};