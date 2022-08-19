class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        vector<array<int, 3>> v;
        for (auto i = 0; i < m; ++i)
            for (auto j = 0; j < n; ++j)
                v.push_back({grid[i][j], i, j});
        sort(begin(v), end(v));

        vector<int> rows(m,0), cols(n,0);
        for (auto &[vv, i, j] : v)
        {
            grid[i][j] = max(rows[i], cols[j]) + 1;
            rows[i] = cols[j] = grid[i][j]; 
        }
        return grid; 
    }
};