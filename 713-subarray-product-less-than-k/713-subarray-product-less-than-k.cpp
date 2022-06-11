class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 1, ans = 0;
        for(int i=0, j =0; j<n;j++){
            sum *=nums[j];
            while(i<n && sum>=k){
                sum/=nums[i];
                i++;
            }
            if(sum<k)
                ans+= j-i+1;
            
        }
        return ans;
    }
};