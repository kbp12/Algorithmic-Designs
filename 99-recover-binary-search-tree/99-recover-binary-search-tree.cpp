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
    vector<TreeNode*>temp;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        temp.push_back(root);
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int n = temp.size();
        for(int i=0;i<n;i++) cout<<temp[i]->val<<" ";
        for(int i=1;i<n;i++){
            if(temp[i]->val<temp[i-1]->val){
                int j=i-1;
                while(i<n && temp[i]->val<temp[j]->val)i++;
                swap(temp[i-1]->val,temp[j]->val);
                break;
            }
        }
        return;
    }
};