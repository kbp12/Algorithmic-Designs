class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<int>x = {-1,1,0,0};
        vector<int>y = {0,0,1,-1};
        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [a,b] = q.front(); q.pop();
                for(int k=0;k<4;k++){
                    int i = a+x[k], j = b+y[k];
                    if(i>=0 and i<n and j>=0 and j<m and rooms[i][j]==INT_MAX){
                        rooms[i][j] = dist;
                        q.push({i,j});
                    }
                }
            }
            dist++;
        }
        return;
    }
};