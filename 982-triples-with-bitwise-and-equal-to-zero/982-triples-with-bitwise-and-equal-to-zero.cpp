class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                umap[nums[i] & nums[j]]++;
            }
        }
        int ans = 0;
        for(auto &it:umap){
            for(int k=0;k<n;k++){
                if((nums[k] & it.first)==0) ans+=it.second;
            }
        }
        return ans;
    }
};