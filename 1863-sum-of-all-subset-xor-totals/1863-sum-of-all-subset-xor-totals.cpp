class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orr = 0;
        for(auto num:nums) orr = orr | num;
        int n = nums.size();
        return (orr<<(n-1));
    }
};