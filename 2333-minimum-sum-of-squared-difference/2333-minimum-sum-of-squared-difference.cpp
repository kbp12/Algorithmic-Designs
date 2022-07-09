class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long>dp(1e5+1,0);
        for(int i=0;i<n;i++){
            long long diff = abs(nums1[i]-nums2[i]);
            dp[diff]++;
        }
        long long k = k1+k2;
        for(int i=1e5;i>0;i--){
            if(dp[i]>0 && k>=dp[i]){
                dp[i-1]+=dp[i];
                k-=dp[i];
                dp[i] = 0;
            }else if(dp[i]>0){
                dp[i-1]+=k;
                dp[i]-=k;
                k=0;
            }
        }
        long long ans = 0;
        for(long long i=1;i<=1e5;i++){
            while(dp[i]){
                ans+=(i*i);
                dp[i]--;
            }
        }
        return ans;
    }
};