class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>u;
        int prev = INT_MAX;
        int s = 0;
        for(int i=0;i<n;i++){
            s+= nums[i];
            int a = s%k;
            if(a==0 && i!=0) return true; 
            if(u.find(a)!=u.end()) return true;
            u.insert(prev);
            prev = a;
        }
        return false;
    }
};

 