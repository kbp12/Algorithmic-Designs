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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*>q; q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* f = q.front(); q.pop();
                if(f->left){
                    if(f->val%2==0){
                        if(f->left->left){
                            sum+= f->left->left->val;
                        }
                        if(f->left->right){
                            sum+= f->left->right->val;
                        }
                    }
                    q.push(f->left);
                }
                if(f->right){
                    if(f->val%2==0){
                        if(f->right->left){
                            sum+= f->right->left->val;
                        }
                        if(f->right->right){
                            sum+= f->right->right->val;
                        }
                    }
                    q.push(f->right);
                }
            }
        }
        return sum;
    }
};