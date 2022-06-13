class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zor = 0;
        for(auto num:nums) zor = zor xor num;
        return zor;
    }
};