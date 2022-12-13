class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        for(int i=0;i<n;i++) sort(grid[i].begin() , grid[i].end());
        int ans = 0;
        for(int j=0;j<m;j++){
            int val = 0;
            for(int i=0;i<n;i++){
                val = max(val , grid[i][j]);
            }
            ans+=val;
        }
        return ans;
    }
};