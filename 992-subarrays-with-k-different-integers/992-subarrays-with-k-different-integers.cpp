class Solution {
public:
    
    int subarrWithatmostK(vector<int>& nums, int k, int n){
        unordered_map<int,int>umap;
        int i = 0, ans = 0;
        for(int j=0;j<n;j++){
            if(umap[nums[j]]==0){
                umap[nums[j]]++; k--;
            }else{
                umap[nums[j]]++;
            }
            while(k<0){
                if(umap[nums[i]]==1){
                    k++;
                }
                umap[nums[i]]--;
                i++;
            }
            ans+= j-i+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return subarrWithatmostK(nums,k,n)-subarrWithatmostK(nums,k-1,n);
    }
};