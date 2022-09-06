class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int c = 0;
                for(int k=0;k<n;k++){
                    if(grid[k][i] and grid[k][j]) c++;
                }
                if(c){
                    ans+=(c*(c-1))/2;
                }
            }
        }
        return ans;
    }
};