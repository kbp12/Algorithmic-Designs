class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>player(n);
        for(int i=0;i<n;i++){
            player[i] = {efficiency[i],speed[i]};
        }
        sort(player.begin(),player.end(), greater<pair<int,int>>());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        long long sum = 0;
        long long ans = 0;
        long long mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(pq.size()>=k){
                int val = pq.top().first; pq.pop();
                sum-=val;
            }
            pq.push({player[i].second,player[i].first});
            sum+= player[i].second;
            mini = player[i].first;
            ans = max(ans,sum*mini);
        }
        int mod = 1e9+7;
        return ans%(mod);
    }
};