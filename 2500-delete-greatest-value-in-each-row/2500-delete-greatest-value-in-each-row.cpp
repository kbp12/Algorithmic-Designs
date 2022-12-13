class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<priority_queue<int>>v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i].push(grid[i][j]);
            }
        }
        int ans = 0;
        while(m--){
            int val = 0;
            for(int i=0;i<n;i++){
                int f = v[i].top(); v[i].pop();
                val = max(val , f);
            }
            ans+=val;
        }
        return ans;
    }
};