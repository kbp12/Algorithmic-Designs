class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, ans = 0;
        for(auto num:nums){
            if(num==1) curr++;
            else{
                ans = max(ans,curr); curr = 0;
            }
        }
        return max(ans,curr);
    }
};