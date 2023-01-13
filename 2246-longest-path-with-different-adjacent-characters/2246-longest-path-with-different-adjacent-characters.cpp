    class Solution {
public:
    int dfs(vector<vector<int>>& tree, string& s, int& ans, int idx) {
        int first = 0, second = 0;
        for (int i : tree[idx]) {
            int curr = dfs(tree,s,ans,i);
            if (s[idx] == s[i]) continue;
            if(curr>first){ second = first; first = curr; }
            else if(curr>second) second = curr;
        }
        ans = max(ans,first+second+1);
        return first+1;
    }
        
    int longestPath(vector<int>& p, string s) {
        int n = p.size(), ans = 0;
        vector<vector<int>> tree(n, vector<int>());
        for (int i=1;i<n;i++)
            tree[p[i]].push_back(i);
        dfs(tree, s, ans, 0);
        return ans;
    }
};