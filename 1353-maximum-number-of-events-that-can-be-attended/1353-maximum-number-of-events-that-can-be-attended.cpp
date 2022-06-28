class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),
             [](vector<int>& event1,vector<int>&event2){
            return event1[0]<event2[0];
        });
        
        int today = 1, end_day = 0,idx = 0, n = events.size();
        for(int i=0;i<n;i++){
            end_day = max(end_day,events[i][1]);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int events_attended = 0;
        while(today<=end_day){
            while(!pq.empty() && pq.top()<today){
                pq.pop();
            }
            while(idx<n && events[idx][0]==today){
                pq.push(events[idx][1]); idx++;
            }
            if(!pq.empty()){
                events_attended++;
                pq.pop();
            }
            today++;
        }
        
        return events_attended;
    }
};