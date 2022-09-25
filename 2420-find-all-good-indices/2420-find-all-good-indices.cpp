class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n,1),back(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                pref[i] = pref[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                back[i] = back[i+1]+1;
            }
        }
        vector<int>ans;
        for(int i=k;i<n-k;i++){
            if(pref[i-1]>=k and back[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};