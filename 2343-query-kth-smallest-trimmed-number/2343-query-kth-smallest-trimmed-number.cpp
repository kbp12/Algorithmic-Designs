class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans(m);
        for(int k=0;k<m;k++){
            int f = queries[k][0], s = queries[k][1];
            vector<pair<string,int>>temp(n);
            for(int i=0;i<n;i++){
                int siz = nums[i].size();
                temp[i] = {nums[i].substr(siz-s), i};
            }
            sort(temp.begin(),temp.end());
            ans[k] = temp[f-1].second;
        }
        return ans;
    }
};