class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int temp = 0;
                for(int k=i;k<i+3;k++){
                    for(int b=j;b<j+3;b++) temp+=grid[k][b];
                }
                temp-=(grid[i+1][j]);
                temp-=(grid[i+1][j+2]);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};