class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m,-1);
        for(int k=0;k<m;k++){
            int i = 0, j = k;
            bool ok  = true;
            while(ok and i<n){
                if(grid[i][j] == 1){
                    if(j>=m-1 or grid[i][j+1]==-1){
                        ok = false;
                    }else{
                        i++; j++;
                    }
                }else{
                    if(j<=0 or grid[i][j-1]==1){
                        ok = false;
                    }else{
                        i++; j--;
                    }
                }
            }
            if(ok and i==n){
                ans[k] = j;
            }
        }
        return ans;
    }
};