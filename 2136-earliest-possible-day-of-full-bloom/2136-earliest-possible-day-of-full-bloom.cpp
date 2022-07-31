class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        vector<vector<int>>v(n,vector<int>(2));
        for(int i=0;i<n;i++){
            v[i][0] = growTime[i];
            v[i][1] = i;
        }
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]>b[0]) return true;
            if(a[0]<b[0]) return false;
            return a[1]<b[1];
        });
        
        int ans = INT_MIN;
        int till = 0;
        for(int i=0;i<n;i++){
            till += plantTime[v[i][1]];
            ans = max(ans,till+v[i][0]);
        }
        
        return ans;
    }
};