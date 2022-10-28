class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, ans = 0, n = nums.size();
        for(auto num:nums) maxi |= num;
        for(int mask = 1; mask<(1<<n);mask++){
            int orr = 0;
            for(int i=0;i<n;i++){
                if((mask>>i) & 1){
                    orr |= nums[i];
                }
            }
            if(orr == maxi) ans++;
        }
        return ans;
    }
};