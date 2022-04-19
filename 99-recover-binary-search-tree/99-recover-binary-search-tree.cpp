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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* first = NULL, *second = NULL;
        TreeNode* temp = NULL;
		while(root!=NULL){
			if(root->left!=NULL){
				temp = root->left;
				while(temp->right!=NULL && temp->right != root) temp = temp->right;
				
				if(temp->right!=NULL){
				    if(pre!=NULL && pre->val > root->val){
				        if(first==NULL)first = pre;
				        second = root;
				    }
				    pre = root;
					temp->right = NULL;
					root = root->right;
				}else{
					temp->right = root;
					root = root->left;
				}
			}else{
				if(pre!=NULL && pre->val > root->val){
				    if(first==NULL)first = pre;
				    second = root;
				}
				pre = root;
				root = root->right;
			}
		}
		int t = first->val;
		first->val = second->val;
		second->val = t;
        return;
    }
};