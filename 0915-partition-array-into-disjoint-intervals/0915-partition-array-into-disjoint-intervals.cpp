class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n,INT_MAX) , r(n,INT_MAX);
        l[0] = nums[0] , r[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            l[i] = max(l[i-1] , nums[i]);
            r[n-1-i] = min(r[n-i] , nums[n-1-i]);
        }
        for(int i=0;i<n-1;i++){
            if(l[i] <= r[i+1]) return i+1;
        }
        return -1;
    }
};