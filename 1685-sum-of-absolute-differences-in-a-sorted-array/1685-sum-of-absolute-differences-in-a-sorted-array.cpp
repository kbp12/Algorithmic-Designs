class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        long long n = nums.size();
        vector<long long>left(n , 0) , right(n , 0);
        left[0] = nums[0];
        for(int i=1;i<n;i++){
            left[i] = left[i-1] + nums[i];
        }
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] + nums[i];
        }
        vector<int>ans(n);
        for(long long i=0;i<n;i++){
            long long l = (i+1)*nums[i] - left[i];
            long long r = right[i] - (n-i)*nums[i];
            ans[i] = l+r;
        }
        return ans;
    }
};