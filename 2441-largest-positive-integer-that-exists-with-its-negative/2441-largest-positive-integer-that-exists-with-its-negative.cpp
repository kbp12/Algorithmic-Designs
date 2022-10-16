class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int>s;
        for(auto num:nums){
            if(num>0) s.insert(num);
        }
        int ans = -1;
        for(auto num:nums){
            if(num<0 and s.find((-num))!=s.end()) ans = max(ans,(-num));
        }
        return ans;
    }
};