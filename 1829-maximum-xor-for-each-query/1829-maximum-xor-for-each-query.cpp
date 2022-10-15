class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorr = 0, n = nums.size();
        for(int i=0;i<n;i++) xorr = xorr xor nums[i];
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int res = 0;
            for(int j=0;j<maximumBit;j++){
                if(((xorr>>j) & 1)==0) res+=pow(2,j);
            }
            xorr = xorr xor nums[i];
            ans[n-1-i] = res;
        }
        return ans;
    }
};