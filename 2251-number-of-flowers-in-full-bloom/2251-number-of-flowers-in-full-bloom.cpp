class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int>start,end;
        for(int i=0;i<f.size();i++){
            start.push_back(f[i][0]);
            end.push_back(f[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            int a = p[i];
            int s = upper_bound(start.begin(),start.end(),a)-start.begin();
            int e = lower_bound(end.begin(),end.end(),a)-end.begin();
            ans.push_back(s-e);
        }
        return ans;
    }
};