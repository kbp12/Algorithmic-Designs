class Solution {
public:
    int maxi, ans;
    void backtrack(vector<bool>& v , vector<int>& nums , int idx){
        if(idx == nums.size()){
            int orr = 0;
            for(int i=0;i<nums.size();i++){
                if(v[i]) orr |= nums[i];
            }
            if(orr == maxi){
                ans++;
            }
            return;
        }
        backtrack(v,nums,idx+1);
        v[idx] = true;
        backtrack(v,nums,idx+1);
        v[idx] = false;
        return;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        maxi = 0 , ans = 0;
        for(auto num:nums) maxi |= num;
        int n = nums.size();
        vector<bool>v(n,false);
        backtrack(v,nums,0);
        return ans;
    }
};