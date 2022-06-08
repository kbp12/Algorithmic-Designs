class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size(), m = req.size();
        vector<int>count(n,0);
        for(int i=0;i<m;i++){
            int a = req[i][0], b = req[i][1];
            count[a]++;
            if(b<n-1) count[b+1]--;
        }
        for(int i=1;i<n;i++) count[i]+=count[i-1];
        sort(count.begin(),count.end());
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans+= (long long)count[i]*nums[i];
        }
        return ans%1000000007;
    }
};