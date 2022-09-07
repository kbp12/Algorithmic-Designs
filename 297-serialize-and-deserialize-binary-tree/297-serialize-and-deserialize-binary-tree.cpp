/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string s;
    void ser(TreeNode* root){
        if(!root){
            s+="#";
            return;
        }
        s+=to_string(root->val);
        s+=",";
        ser(root->left);
        s+=",";
        ser(root->right);
        return;
    }
    string serialize(TreeNode* root) {
        s = "";
        ser(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deser(string &s){
        int val;
       if(s[0]=='#'){
           if(s.size()>1)s=s.substr(2);
           return nullptr;
       }else{
           int pos=s.find(',');
           int v=stoi(s.substr(0,pos));
           s=s.substr(pos+1);
           val=v;
       }
        TreeNode* root = new TreeNode(val);
        root->left=deser(s);
        root->right=deser(s);
        return root;
    }
    
    TreeNode* deserialize(string data) {
        return deser(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));