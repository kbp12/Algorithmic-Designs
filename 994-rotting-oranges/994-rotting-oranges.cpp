class Solution {
public:
    bool isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fr = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fr++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fr==0) return 0;
        vector<int>x = {-1,0,1,0};
        vector<int>y = {0,1,0,-1};
        
        int ans = 1;
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0; i<siz; i++){
                auto it = q.front(); q.pop();
                int f = it.first, s = it.second;
                for(int j=0;j<4;j++){
                    if(isValid(f+x[j], s+y[j],m,n) && grid[f+x[j]][s+y[j]]==1){
                        fr--;
                        grid[f+x[j]][s+y[j]] = 2;
                        q.push({f+x[j], s+y[j]});
                    }
                }
            }
            if(fr==0) return ans;
            ans++;
        }
        if(fr) return -1;
        return ans;
    }
};