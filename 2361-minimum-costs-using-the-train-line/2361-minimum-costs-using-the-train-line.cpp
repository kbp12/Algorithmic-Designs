class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector<long long>toreg(n+1,0);
        vector<long long>toexp(n+1,0);
        vector<long long>dist(n);
        toexp[0] = expressCost;
        for(int i=1;i<=n;i++){
            toreg[i] = min(toreg[i-1]+regular[i-1],toexp[i-1]+regular[i-1]);
            toexp[i] = min(toreg[i]+expressCost,toexp[i-1]+express[i-1]);
            dist[i-1] = min(toreg[i],toexp[i]);
        }
        return dist;
    }
};