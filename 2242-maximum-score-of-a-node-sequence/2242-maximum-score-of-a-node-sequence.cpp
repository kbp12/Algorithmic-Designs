class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector <vector<int>> g(n);
        for (auto it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](const auto a1, const auto a2) {
                return scores[a1] > scores[a2];
            });
        }
        int ans = INT_MIN;
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i < (g[u].size()) and j < (g[v].size()) and g[u][i]!=g[v][j] and u != g[v][j] and v != g[v][j] and u != g[u][i] and v != g[u][i]) {
                        ans = max(ans, scores[u] + scores[v] + scores[g[u][i]] + scores[g[v][j]]);
                    }
                }
            }
        }
        return ans==INT_MIN? -1:ans;
    }
};