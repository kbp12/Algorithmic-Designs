class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx{-1, 1, 0, 0};
        vector<int> dy{0, 0, -1, 1}; 
        vector<vector<int>> D = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            for (int k = 0; k < 4; ++k) {
                int i2 = i + dx[k];
                int j2 = j + dy[k];
                if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n) {
                    if (int d2 = d + grid[i2][j2]; d2 < D[i2][j2]) {
                        D[i2][j2] = d;
                        pq.emplace(d2, i2, j2);
                    }
                }
            }
        }
        return D[m - 1][n - 1];
    }
};