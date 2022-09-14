class Solution {
public:
    int dp[16][65536] = {};
int dfs(int i, vector<vector<array<int, 2>>> &al, int mask, int k) {
    if (k == 0)
        return 0;
    if (dp[i][mask] == 0) {
        dp[i][mask] = INT_MIN;
        for (auto [j, cost] : al[i])
            if (((1 << j) & mask) == 0)
                dp[i][mask] = max(dp[i][mask], cost + dfs(j, al, mask + (1 << j), k - 1));
    }
    return dp[i][mask];
}
int maximumCost(int n, vector<vector<int>>& highways, int k) {
    if (k > n - 1)
        return -1;
    vector<vector<array<int, 2>>> al(n);
    for (auto &h : highways) {
        al[h[0]].push_back({h[1], h[2]});
        al[h[1]].push_back({h[0], h[2]});
    }
    int res = INT_MIN;
    for (int i = 0; i < n; ++i)
        res = max(res, dfs(i, al, (1 << i), k));
    return res < 0 ? -1 : res;
}
};