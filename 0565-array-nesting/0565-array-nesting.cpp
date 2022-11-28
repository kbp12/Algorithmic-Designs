class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<bool>visit(n,false);
        for(auto i:nums){
            int dfsdepth = 0;
            while(visit[i]==false){
                dfsdepth++;
                visit[i] = true;
                i = nums[i];
            }
            ans = max(ans,dfsdepth);
        }
        return ans;
    }
};