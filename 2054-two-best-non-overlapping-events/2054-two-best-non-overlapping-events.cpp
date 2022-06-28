class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // let's sort the events according to start time, and traverse through them in order
        sort(events.begin(),events.end());
        // say I want to access the end time of previous events
        // The event that I want should be earliest ending so that I can try to combine it
        // with the current event to get a possible sum
        // We store the maximum of all such sums and return it
        
        // To get such event the best data structure is priouity queue
        
        // How? I will store the event end time and its corresponding value in a pair and 
        // store it into min heap(priority queue).
        // Why min heap? As stated earlier we need those events whose end time is as low
        // as possible so storing the previous events in min heap.
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq's element = {end time of event, it's value} 
        
        int ans = 0, prev_max_value = 0;
        for(auto event:events){
            
            // if there is a element in 'pq' and if the end time of it if less than current
            // event's start time then we try to get the maxvalue from one such event 
            while(pq.size() && pq.top().first<event[0]){
                prev_max_value = max(prev_max_value,pq.top().second);
                pq.pop();
            }
            
            ans = max( ans, prev_max_value+event[2]);
            pq.push({event[1],event[2]});
        }
        return ans;
    }
};