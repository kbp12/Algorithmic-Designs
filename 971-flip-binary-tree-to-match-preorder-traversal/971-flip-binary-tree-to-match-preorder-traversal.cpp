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
    vector<int>ans;
    int i;
    bool find(TreeNode* root, vector<int>&v){
        if(root==NULL) return true;
        if(root->val == v[i]){
            i++;
            if(root->left){
                if(root->left->val == v[i]){
                    bool l = find(root->left,v);
                    bool r = find(root->right,v);
                    if(l&&r) return true;
                    return false;
                }else{
                    ans.push_back(root->val);
                    bool l = find(root->right,v);
                    bool r = find(root->left,v);
                    if(l&&r) return true;
                    return false;
                }
            }else{
                bool r = find(root->right,v);
                return r;
            }
        }else{
            return false;
        }
        return true;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        i=0;
        bool a = find(root,v);
        if(a==false) return {-1};
        return ans;
    }
};