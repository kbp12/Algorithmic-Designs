class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        map<vector<int>,int>row,col;
        for(int i=0;i<n;i++){
            
            vector<int>t(n);
            for(int j=0;j<n;j++){
                t[j] = grid[i][j];
            }
            row[t]++;
        }
        for(int i=0;i<n;i++){
            
            vector<int>t(n);
            for(int j=0;j<n;j++){
                t[j] = grid[j][i];
            }
            col[t]++;
        }
        int ans = 0;
        
        for(auto itr:row){
            
            ans+= (col[itr.first]*itr.second);
        }
        return ans;
    }
};