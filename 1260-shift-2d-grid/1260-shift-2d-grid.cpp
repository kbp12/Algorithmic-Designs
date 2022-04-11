class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        int m = grid.size(), n = grid[0].size();
        k = k%(m*n);
        for(int x=0;x<k;x++){
            int temp = grid[m-1][n-1];
            for(int i=m-1;i>=0;i--){
                for(int j=n-1;j>=0;j--){
                    if(i==0 && j==0){
                        grid[i][j] = temp;
                    }else if(j!=0){
                        grid[i][j]=grid[i][j-1];
                    }else{
                        grid[i][j]=grid[i-1][n-1];
                    }
                }
            }
        }
        return grid;
    }
};