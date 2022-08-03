class Solution {
public:
    vector<int>dfsdepth;
    vector<bool>visit;

    void dfs(vector<int>& nums, int i){
        if(nums[i]==0){
            visit[i] = true;
            dfsdepth[i] = 1;
            return;
        }
        if(dfsdepth[nums[i]]!=-1){
            dfsdepth[i] = dfsdepth[nums[i]]+1;
            return;
        }
        if(visit[nums[i]] or nums[i]==i){
            dfsdepth[i] = 1;
            visit[i] = true;
            return;
        }
        visit[i] = true;
        dfs(nums,nums[i]);
        dfsdepth[i] = dfsdepth[nums[i]]+1;
        return;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        dfsdepth = vector<int>(n,-1);
        visit = vector<bool>(n,false);
        for(int i=0;i<n;i++){
            if(dfsdepth[i]==-1){
                dfs(nums,i);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dfsdepth[i]);
        }
        return ans;
    }
};