class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void permutations(vector<int>nums, int j){
        if(j==nums.size()){
            ans.push_back(nums);
            return;
        }
        cout<<j<<" ";
        for(int i=j;i<nums.size();i++){
            swap(nums[i],nums[j]);
            permutations(nums,j+1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        permutations(nums,0);
        return ans;
    }
};