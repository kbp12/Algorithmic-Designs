class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int ans = 0;
        for(int i=0;i<n;i++){
            int st = intervals[i][0];
            while(pq.size() and pq.top()<=st){
                pq.pop();
            }
            int end = intervals[i][1];
            if(pq.size()==0 or (pq.size() and pq.top()>st)){
                pq.push(end);
            }
            int sz = pq.size();
            ans = max(ans,sz);
        }
        return ans;
    }
};