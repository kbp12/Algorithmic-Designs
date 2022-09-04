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
    void traverse(TreeNode* root, vector<vector<int>>&temp, int x, int y){
        if(!root) return;
        traverse(root->left,temp,x+1,y-1);
        traverse(root->right,temp,x+1,y+1);
        vector<int>t;
        t.push_back(y);
        t.push_back(x);
        t.push_back(root->val);
        temp.push_back(t);
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        vector<vector<int>>temp;
        traverse(root,temp,0,0);
        sort(temp.begin(),temp.end(),[](vector<int>& v1, vector<int>&v2){
        if(v1[0]<v2[0]) return true;
        if(v1[0]>v2[0]) return false;
        if(v1[1]<v2[1]) return true;
        if(v1[1]>v2[1]) return false;
        return v1[2]<v2[2];
    });
        int n = temp.size();
        int curry = INT_MIN;
        vector<int>topush;
        for(int i=0;i<n;i++){
            if(temp[i][0]!=curry){
                if(topush.size())
                    ans.push_back(topush);
                topush.clear();
                topush.push_back(temp[i][2]);
                curry = temp[i][0];
            }else{
                topush.push_back(temp[i][2]);
            }
        }
        if(topush.size())
            ans.push_back(topush);
        
        return ans;
    }
};