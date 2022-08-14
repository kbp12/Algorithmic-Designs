class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        vector<int>x = {0,0,-1,-1,-1,0,1,1,1};
        vector<int>y = {0,-1,-1,0,1,1,1,0,-1};
        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                ans[i-1][j-1] = INT_MIN;
                for(int k=0;k<9;k++){
                    ans[i-1][j-1] = max(ans[i-1][j-1],grid[i+x[k]][j+y[k]]);
                }
            }
        }
        return ans;
    }
};