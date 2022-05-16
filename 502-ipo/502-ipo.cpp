class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int n = p.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i] = {c[i],p[i]};
        }
        sort(v.begin(),v.end(),[](pair<int,int>p1,pair<int,int>p2){
            if(p1.first<p2.first) return true;
            else if(p1.first==p2.first){
                return p1.second>p2.second;
            }else{
                return false;
            }
        });
        int ans = w;
        int i=0;
        priority_queue<int>pq;
        while(k){
            while(i<n && v[i].first<=ans){
                pq.push(v[i].second);
                i++;
            }
            if(pq.size()){
                ans+= pq.top(); pq.pop();
            }
            k--;
        }
        return ans;
    }
};