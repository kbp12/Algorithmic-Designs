class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        for(int i=1;i<n;i++){
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            for(int j=0;j<k;j++){
                if(costs[i-1][j]<min1){
                    min2 = min1;
                    min1 = costs[i-1][j];
                }else if(costs[i-1][j]<min2){
                    min2 = costs[i-1][j];
                }
            }
            for(int j=0;j<k;j++){
                if(costs[i-1][j]!=min1){
                    costs[i][j]+=min1;
                }else{
                    costs[i][j]+=min2;
                }
            }
        }
        int ans = INT_MAX;
        for(int j=0;j<k;j++){
            ans = min(ans,costs[n-1][j]);
        }
        return ans;
    }
};