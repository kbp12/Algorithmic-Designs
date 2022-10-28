class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>umap;
        umap[0] = 1;
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = (sum%k + k)%k;
            umap[rem]++;
        }
        for(auto it: umap){
            int p = it.second;
            ans+=(p*(p-1))/2;
        }
        return ans;
    }
};