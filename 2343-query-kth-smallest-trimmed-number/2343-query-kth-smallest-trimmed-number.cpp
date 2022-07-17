class Solution {
public:
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        int n = nums.size(); 
        int m = q.size();
        vector<int>res(m,0);
        for(int i=0;i<m;i++){  
            vector<pair<string,int>>v(n);
            for(int j=0;j<n;j++){
                v[j] = {nums[j],j};
            }
            int f = q[i][0], s = q[i][1];
            for(int j=0;j<n;j++){
                int siz = v[j].first.size(); 
                int st = siz-s; 
                while(st<siz-1 && v[j].first[st]=='0') st++;
                    v[j].first = v[j].first.substr(st);
            }
            sort(v.begin(),v.end(),
                [](pair<string,int>&a, pair<string,int>&b){
                        int c = a.first.size();
                        int d = b.first.size();
                        if(c!=d) return c<d;
                        if(a.first!=b.first) 
                            return a.first<b.first;
                        return a.second<b.second;
                });
            res[i] = v[f-1].second;
            v.clear();
        }
        return res;
    }
};