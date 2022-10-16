class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a  = nums[i];
            int val = 0;
            while(a){
                int r = a%10;
                val = val*10 + r;
                a = a/10;
            }
            nums.push_back(val);
        }
        set<int>s;
        for(auto num:nums) s.insert(num);
        return s.size();
    }
};