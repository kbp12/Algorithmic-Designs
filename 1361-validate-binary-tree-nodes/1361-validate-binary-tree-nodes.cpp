class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parentFreq(n);
        for (int i = 0; i < n; i++)
            if ((leftChild[i] >= 0 and ++parentFreq[leftChild[i]] > 1) or (rightChild[i] >= 0 and ++parentFreq[rightChild[i]] > 1))
                return false;
       
        int root = -1;
        for (int i = 0; i < n; i++)
            if (!parentFreq[i]) {
                if (root == -1)
                    root = i;
                else return false;
            }
        return countNodes(leftChild, rightChild, root) == n;
    }
    
    int countNodes(vector<int> &left, vector<int> &right, int root) {
        if (root == -1)
            return 0;
        return 1 + countNodes(left, right, left[root]) + countNodes(left, right, right[root]);
    }
};