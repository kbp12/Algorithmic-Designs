class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), ans = 1, j = 1, i = 0, d = 32;
        while(j<n){
            bool y = true;
            for(int k=j-1;k>=i and d; k--){
                if(nums[j] & nums[k]){
                    y = false;
                    break;
                }
                d--;
            }
            if(y){ans = max(ans,j-i+1);     j++;
            }else  i++;
            d = 32;
        }
        return ans;
    }
};