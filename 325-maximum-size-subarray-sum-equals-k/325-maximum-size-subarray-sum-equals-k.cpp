class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long,int>umap;
        long long sum = 0;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                ans = i+1;
            }
            if(umap.find(sum-k)!=umap.end()){
                ans = max(ans,i-umap[sum-k]);
            }
            if(umap.find(sum)==umap.end())
                umap[sum] = i;
        }
        return ans;
    }
};