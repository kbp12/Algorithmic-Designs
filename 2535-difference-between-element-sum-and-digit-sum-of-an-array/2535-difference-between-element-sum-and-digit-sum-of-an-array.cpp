class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s1 = 0 , s2 =0;
        for(auto num:nums){
            s1+=num;
            while(num){
                s2+=num%10;
                num/=10;
            }
        }
        return abs(s1-s2);
    }
};