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
    TreeNode* getlca(TreeNode* root, int s, int d){
        if(!root) return NULL;
        if(root->val==s || root->val==d) return root;
        TreeNode* l = getlca(root->left,s,d);
        TreeNode* r = getlca(root->right,s,d);
        if(l and r) return root;
        if(l) return l;
        return r;
    }
    
    string fromst="";
    bool getstpath(TreeNode* root, int st){
        if(!root) return false;
        if(root->val==st) return true;
        bool l = getstpath(root->left,st);
        bool r = getstpath(root->right,st);
        if(l || r){
            fromst+= "U";
            return true;
        }
        return false;
    }
    
    string todest="";
    bool getdpath(TreeNode* root, int d){
        if(!root) return false;
        if(root->val==d) return true;
        bool l = getdpath(root->left,d);
        bool r = getdpath(root->right,d);
        if(l){
            todest+="L";
            return true;
        }else if(r){
            todest +="R";
            return true;
        }
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getlca(root,startValue,destValue);
        getstpath(lca,startValue);
        getdpath(lca,destValue);
        reverse(todest.begin(),todest.end());
        return fromst+todest;
    }
};