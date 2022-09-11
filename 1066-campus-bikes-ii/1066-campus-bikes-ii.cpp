class Solution {
public:
    int ans;
    void dfs(int workers[][2], int bikes[][2], bool assigned[],int idx, int sum, int n, int m){
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
    
    int assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
        int n = w.size();
        int workers[n][2];
        for(int i=0;i<n;i++) workers[i][0] = w[i][0], workers[i][1] = w[i][1];
        int m = b.size();
        int bikes[m][2];
        for(int i=0;i<m;i++) bikes[i][0] = b[i][0], bikes[i][1] = b[i][1];
        ans = INT_MAX;
        bool assigned[m];
        for(int i=0;i<m;i++) assigned[i] = false;
        dfs(workers,bikes,assigned,0,0,n,m);
        return ans;
    }
};