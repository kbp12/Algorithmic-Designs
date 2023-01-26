class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int>l(n,0);
        if(nums[0]) l[0] = 1;
        for(int i=1;i<n;i++){
            if(nums[i]) l[i] = l[i-1]+1;
        }
        vector<int>r(n,0);
        if(nums[n-1]) r[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]) r[i] = r[i+1]+1;
        }
        int ans = max(l[1] , r[n-2]);
        for(int i=1;i<n-1;i++){
            ans = max(ans , l[i-1] + r[i+1]);
        }
        return ans;
    }
};