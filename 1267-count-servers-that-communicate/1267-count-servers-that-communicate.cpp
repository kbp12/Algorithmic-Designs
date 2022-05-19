class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        vector<vector<int>>v(m+n);
        for(int i=0;i<m;i++){
            for(int j=m;j<m+n;j++){
                if(grid[i][j-m]){
                    total++;
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        for(int k=0;k<n+m;k++){
            if(v[k].size()==1){
                int p = v[k][0];
                if(v[p].size()==1){
                    total--;
                    v[k].clear();
                    v[p].clear();
                }
            }
        }
        return total;
    }
};