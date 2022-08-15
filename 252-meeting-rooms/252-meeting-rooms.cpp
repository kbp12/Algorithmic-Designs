class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int prev = -1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<prev){
                return false;
            }
            prev = max(prev,intervals[i][1]);
        }
        return true;
    }
};