class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_map<int,int>umap;
        int ans = 1;
        for(auto it:nums){
            if(umap[it]) continue;
            else if(umap.find(it+1)==umap.end() && umap.find(it-1)==umap.end()) umap[it] = 1;
            else if(umap.find(it-1)==umap.end()){
                umap[it] = umap[it+1]+1;
                umap[it+umap[it+1]] = umap[it];
                ans = max(ans,umap[it]);
            }else if(umap.find(it+1)==umap.end()){
                umap[it] = umap[it-1]+1;
                umap[it-umap[it-1]] = umap[it];
                ans = max(ans,umap[it]);
            }else{
                umap[it] = umap[it-1]+umap[it+1]+1;
                umap[it+umap[it+1]] = umap[it];
                umap[it-umap[it-1]] = umap[it];
                ans = max(ans,umap[it]);
            }
        }
        return ans;
    }
};