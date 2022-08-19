class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        bool am[1001][1001] = {};
    for (auto &c : corridors)
        am[min(c[0], c[1])][max(c[0], c[1])] = true;
    int res = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; am[i][j] && k <= n; ++k)
                res += am[j][k] && am[i][k];
    return res;
    }
};