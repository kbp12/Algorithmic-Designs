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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        depth--;
        queue<TreeNode*>q; q.push(root);
        while(q.size()){
            int siz = q.size();
            if(depth==1){
                for(int i=0;i<siz;i++){
                    TreeNode* f = q.front(); q.pop();
                    TreeNode* ff = new TreeNode(val);
                    ff->left = f->left;
                    TreeNode* rr = new TreeNode(val);
                    rr->right = f->right;
                    f->left = ff;
                    f->right = rr;
                }
                break;
            }
            for(int i=0;i<siz;i++){
                TreeNode* f = q.front(); q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            depth--;
        }
        return root;
    }
};