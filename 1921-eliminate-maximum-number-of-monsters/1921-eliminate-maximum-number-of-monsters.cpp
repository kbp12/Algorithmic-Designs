class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i=0;i<n;i++){
            if(dist[i]==1) dist[i] = 0;
            else    dist[i] = (dist[i]/speed[i] + (dist[i]%speed[i]!=0));
        }
        sort(dist.begin() , dist.end());
        for(int i=0;i<n;i++){
            if(dist[i] < i or (dist[i]==i and i!=0)) return i;
        }
        return n;
    }
};