class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //space =  n*m
        //space o(m);
        //row1 = 4 5 6
    //row1=>    row2 = 6 7 8
    //row2=>    row3 = 7 8 9
        vector<int>row1(n),row2(n);
        row1[0] = grid[0][0];
        for(int i=1;i<n;i++){
            row1[i] = row1[i-1] + grid[0][i];
        }
        for(int i=1;i<m;i++){
            row2[0] = row1[0] + grid[i][0];
            for(int j=1;j<n;j++){
                row2[j] = grid[i][j] + min(row2[j-1],row1[j]);
            }
            swap(row1,row2);
        }
        return row1[n-1];
    }
};