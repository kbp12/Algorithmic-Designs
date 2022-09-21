class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto num:nums) if(num%2==0) sum+=num;
        vector<int>ans;
        for(auto query:queries){
            if(nums[query[1]]%2==0) sum-= nums[query[1]];
            nums[query[1]]+=query[0];
            if(nums[query[1]]%2==0) sum+=nums[query[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};