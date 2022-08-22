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
    int minimumFlips(TreeNode* n, bool res) {
        if (n->val < 2)
            return res != n->val;
        if (n->val == 5)
            return n->left != nullptr ? minimumFlips(n->left, !res) : minimumFlips(n->right, !res);
        if (n->val == 2) // OR
            return res ? min(minimumFlips(n->left, true), minimumFlips(n->right, true)) :
                minimumFlips(n->left, false) + minimumFlips(n->right, false);
        if (n->val == 3) // AND
            return res ? minimumFlips(n->left, true) + minimumFlips(n->right, true) :
                min(minimumFlips(n->left, false), minimumFlips(n->right, false));
        int lt = minimumFlips(n->left, true), lf = lt ? 0 : minimumFlips(n->left, false);
        int rt = minimumFlips(n->right, true), rf = rt ? 0 : minimumFlips(n->right, false);            
        return res ? min(lt + rf, lf + rt) : min(lt + rt, lf + rf);
    }
};