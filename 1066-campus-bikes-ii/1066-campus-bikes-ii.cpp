class Solution {
public:
    vector<int>dpmask;
    
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, int widx, int mask){
        if(widx==workers.size()) return 0;
        if(dpmask[mask]!=-1) return dpmask[mask];
        int minsum = INT_MAX;
        for(int b=0;b<bikes.size();b++){
            if((mask & (1<<b)) ==0){
                int add = abs(workers[widx][0]-bikes[b][0])+abs(workers[widx][1]-bikes[b][1]);
                int this_sum = dfs(workers,bikes,widx+1,(mask + (1<<b)))+add;
                minsum = min(minsum,this_sum);
            }
        }
        return dpmask[mask] = minsum;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = bikes.size();
        m = pow(2,m);
        dpmask = vector<int>(m,-1);
        return dfs(workers,bikes,0,0);
    }
};