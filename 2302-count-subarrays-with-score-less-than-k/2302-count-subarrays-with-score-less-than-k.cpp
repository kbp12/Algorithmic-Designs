class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0, sum = 0;
        int n = nums.size();
        for(int i=0,j=0;j<n;j++){
            sum+=nums[j];
            long long p = sum*(j-i+1);
            while(i<n && p>=k){
                sum-=nums[i]; i++;
                p = sum*(j-i+1);
            }
            if(p<k)
                count+=j-i+1;
        }
        return count;
    }
};