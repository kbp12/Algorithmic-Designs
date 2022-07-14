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
    int preidx;
    TreeNode* builtTree(vector<int>&preorder, vector<int>&inorder, int l, int r){
        if(l>r) return NULL;
        int v = preorder[preidx]; 
        preidx++;
        int mid;
        for(mid=l;mid<=r;mid++){
            if(inorder[mid]==v){
                break;
            }
        }
        TreeNode* root = new TreeNode(v);
        root->left = builtTree(preorder,inorder,l,mid-1);
        root->right = builtTree(preorder,inorder,mid+1,r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preidx = 0;
        int l = 0, r = inorder.size()-1;
        return builtTree(preorder,inorder,l,r);
    }
};