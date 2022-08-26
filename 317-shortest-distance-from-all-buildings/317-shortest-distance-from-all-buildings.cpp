class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> total(rows, vector<int> (cols, 0));
        int emptyLandValue = 0;
        int minDist = INT_MAX;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    minDist = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({ row, col });
                    int steps = 0;
                    while (!q.empty()) {
                        steps++;
                        for (int level = q.size(); level > 0; --level) {
                            auto curr = q.front();
                            q.pop();
                            for (auto& dir : dirs) {
                                int nextRow = curr.first + dir[0];
                                int nextCol = curr.second + dir[1];
                                if (nextRow >= 0 && nextRow < rows &&
                                    nextCol >= 0 && nextCol < cols &&
                                    grid[nextRow][nextCol] == emptyLandValue) {
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;
                                    q.push({ nextRow, nextCol });
                                    minDist = min(minDist, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }
                    emptyLandValue--;
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};