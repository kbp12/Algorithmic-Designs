class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int m = queries.size();
        vector<int>ans(m);
        for(int j=0;j<m;j++){
            int val = queries[j];
            int c = 0;
            int i = 0;
            while(i<n){
                c+=nums[i];
                if(c>val) break;
                i++;
            }
            ans[j] = i;
        }
        return ans;
    }
};