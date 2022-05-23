class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>u;
        int prev = INT_MAX;
        long long s = 0;
        for(int i=0;i<n;i++){
            s+= nums[i];
            if(s%k==0 && i!=0) return true; 
            if(u.find(s%k)!=u.end()) return true;
            u.insert(prev);
            prev = s%k;
        }
        return false;
    }
};
