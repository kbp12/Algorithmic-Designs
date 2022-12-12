class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<int>adj[n+1];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            priority_queue<int>pq;
            for(auto next:adj[i]){
                pq.push(vals[next]);
            }
            int K = k, res = 0;
            while(K-- and pq.size() and pq.top() > 0){
                res+=pq.top(); pq.pop();
            }
            res+=vals[i];
            ans = max(ans , res);
        }
        return ans;
    }
};