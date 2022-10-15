class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, n = nums.size(), i = 0;
        while(i<n){
            int val = nums[i];
            i++;
            while(i<n and nums[i]==val) i++;
            ans+=n-i;
        }
        return ans;
    }
};