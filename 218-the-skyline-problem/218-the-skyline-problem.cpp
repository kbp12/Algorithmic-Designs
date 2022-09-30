class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        //pq pair stores height,end as a pair and arranges according to heights
        priority_queue<pair<int,int>>pq;
        int curr_end = -1, cur_h = -1, i = 0;
        vector<vector<int>>ans;
        while(i<n or pq.size()){
            curr_end  = pq.empty()? buildings[i][0]:pq.top().second;
            if(i>=n or buildings[i][0]>curr_end){
                while(pq.size() and pq.top().second<=curr_end) pq.pop();
            }else{
                curr_end = buildings[i][0];
                while(i<n and buildings[i][0]==curr_end){
                    pq.push({buildings[i][2],buildings[i][1]});
                    i++;
                }
            } 
            if(pq.size()) cur_h = pq.top().first;
            else cur_h = 0;
            
            if(ans.size()==0 or ans.back()[1] != cur_h){
                ans.push_back({curr_end, cur_h});
            }
        }
        return ans;
    }
};