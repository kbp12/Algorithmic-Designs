class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        vector<int>interval1 = intervals[0];
        for(int i=1;i<n;i++){
            vector<int> interval2 = intervals[i];
            if(interval1[1]>=interval2[0]){
                interval1[1] = max(interval1[1],interval2[1]);
            }else{
                ans.push_back(interval1);
                interval1 = interval2;
            }
        }
        ans.push_back(interval1);
        return ans;
    }
};