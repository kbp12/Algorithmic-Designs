class Solution {
public:
    // Idea: A valid BT has each node with exactly one parent and exactly one node with no parent (root)
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // map to keep count of no. of parent for each node
        vector<int> parentFreq(n);
        for (int i = 0; i < n; i++)
            if ((leftChild[i] >= 0 and ++parentFreq[leftChild[i]] > 1) or (rightChild[i] >= 0 and ++parentFreq[rightChild[i]] > 1))
                return false;
        // find root (if more than 1 root exist then return false)
        int root = -1;
        for (int i = 0; i < n; i++)
            if (!parentFreq[i]) {
                if (root == -1)
                    root = i;
                else return false;
            }
        // last IMP check: apply dfs on root to calculate total nodes in tree, it should be n
        // this check helps in handling the testcases: 4, [1,0,3,-1], [-1,-1,-1,-1]
        return countNodes(leftChild, rightChild, root) == n;
    }
    
    int countNodes(vector<int> &left, vector<int> &right, int root) {
        if (root == -1)
            return 0;
        return 1 + countNodes(left, right, left[root]) + countNodes(left, right, right[root]);
    }
};