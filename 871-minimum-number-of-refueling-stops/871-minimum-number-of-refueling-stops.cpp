class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int>pq;
        int pos = startFuel;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(stations[i][0]<=pos){
                pq.push(stations[i][1]);
            }else{
                if(pos>=target) break;
                if(pq.empty()) return -1;
                pos+=pq.top(); pq.pop();
                ans++;
                i--;
            }
        }
        while(pos<target){
            if(pq.empty()) return -1;
            pos+=pq.top(); pq.pop();
            ans++;
        }
        return ans;
    }
};