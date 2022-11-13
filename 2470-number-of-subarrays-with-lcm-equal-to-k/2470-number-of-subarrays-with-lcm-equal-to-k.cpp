class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int lcm = 1;
            for(int j=i;j<n and k%nums[j]==0;j++){
                lcm *= (nums[j]/__gcd(lcm , nums[j]));
                if(lcm == k) ans++;
            }
        }
        return ans;
    }
};