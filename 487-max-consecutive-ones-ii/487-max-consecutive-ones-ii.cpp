class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, c = 0, i = 0, j =0;
        int n = nums.size();
        while(j<n){
            if(nums[j]==1){
                ans = max(ans,j-i+1);
                j++; c++;
            }else{
                if(j-i==c){
                    ans = max(ans,j-i+1);
                    j++;
                }else{
                    while(nums[i]!=0){
                        c--; i++;
                    }
                    i++;
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};