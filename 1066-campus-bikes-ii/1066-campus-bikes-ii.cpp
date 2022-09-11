class Solution {
public:
    int ans;
    void dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes, bool assigned[],int idx, int sum, int n, int m){
        if(idx == n){
            ans = min(ans,sum);
            return;
        }
        for(int i=0;i<m;i++){
            if(assigned[i]==false){
                assigned[i] = true;
                int temp = abs(bikes[i][0]-workers[idx][0])+abs(bikes[i][1]-workers[idx][1]);
                sum+=temp;
                dfs(workers,bikes,assigned,idx+1,sum,n,m);
                assigned[i] = false;
                sum-=temp;
            }
        }
        return;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        ans = INT_MAX;
        bool assigned[m];
        for(int i=0;i<m;i++) assigned[i] = false;
        dfs(workers,bikes,assigned,0,0,n,m);
        return ans;
    }
};