class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int *curr = new int [(col + 2) * (col + 2)]();
        int *prev = new int [(col + 2) * (col + 2)]();
        vector<pair<int,int>> step = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        for(int r = row - 1; r >= 0; r--) {
            for(int robo1 = 1; robo1 <= r + 1 && robo1 <= col; robo1++) {
                for(int robo2 = col; robo2 > 0 && robo2 >= col - r; robo2--) {
                    int cherries = robo1 != robo2 ? grid[r][robo1 - 1] + grid[r][robo2 - 1] : grid[r][robo1 - 1];
                    int maxCherries = 0;
                    for(const auto& [x, y]: step) 
                        maxCherries = max(maxCherries, *(prev + (robo1 + x) * (col + 2) + robo2 + y));
                    *(curr + robo1 * (col + 2) + robo2) = cherries + maxCherries;
                }
            }
            swap(curr, prev);
        }
        return *(prev + 1 * (col + 2) + col);
    }
};