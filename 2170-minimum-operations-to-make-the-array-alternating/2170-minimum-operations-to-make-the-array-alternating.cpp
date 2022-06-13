class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int m=0;
        for(int i=0;i<n;i++) m = max(m,nums[i]);
        vector<pair<int,int>>dp(m+1,{0,0});
        for(int i=0;i<n;i++){
            if(i%2){
                dp[nums[i]].second++;
            }else{
                dp[nums[i]].first++;
            }
        }
        int ans=0;
        for(int i=1,j=0,k=0;i<=m;i++){
            int a = dp[i].first,b = dp[i].second;
            ans = max(ans,max(a+k,b+j));
            k = max(k,b);
            j = max(j,a);
        }
        return n-ans;
    }
};