class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<int>v(100005,0);
        int c = 0;
        for(int i=0;i<k;i++){
            if(v[nums[i]]>0){
                v[nums[i]]++;
            }else{
                c++;
                v[nums[i]]++;
            }
            sum+=nums[i];
        }
        long long maxsum = 0;
        if(c == k){
            maxsum = sum;
        }
        for(int i=k;i<n;i++){
            v[nums[i-k]]--;
            if(v[nums[i-k]]==0) c--;
            if(v[nums[i]]>0){
                v[nums[i]]++;
            }else{
                c++;
                v[nums[i]]++;
            }
            sum-=nums[i-k];
            sum+=nums[i];
            if(c == k){
                maxsum = max(maxsum , sum);
            }
        }
        return maxsum;
    }
};