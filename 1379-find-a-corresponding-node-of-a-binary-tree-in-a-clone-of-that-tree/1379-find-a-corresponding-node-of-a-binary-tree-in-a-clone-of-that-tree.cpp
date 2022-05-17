/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        queue<TreeNode*>q;
        q.push(o);
        int ans;
        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            if(temp==t){
                ans = temp->val; break;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        queue<TreeNode*>qq;
        qq.push(c);
        while(!qq.empty()){
            TreeNode* temp = qq.front(); qq.pop();
            if(temp->val == ans) return temp;
            if(temp->left) qq.push(temp->left);
            if(temp->right) qq.push(temp->right);
        }
        return NULL;
    }
};