class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int>onel(n,INT_MAX),twol(n,INT_MAX),threel(n,INT_MAX);
        int prevone = -1;
        int prevtwo = -1;
        int prevthree = -1;
        for(int i=0;i<n;i++){
            if(colors[i]==1){
                onel[i] = 0;
                prevone = 1;
                if(prevtwo!=-1)     twol[i] = prevtwo, prevtwo++;
                if(prevthree!=-1)    threel[i] = prevthree, prevthree++;
            }else if(colors[i]==2){
                twol[i] = 0;
                prevtwo = 1;
                if(prevone!=-1)     onel[i] = prevone, prevone++;
                if(prevthree!=-1)    threel[i] = prevthree, prevthree++;
            }else{
                threel[i] = 0;
                prevthree = 1;
                if(prevone!=-1)     onel[i] = prevone, prevone++;
                if(prevtwo!=-1)    twol[i] = prevtwo, prevtwo++;
            }
        }
        
        vector<int>oner(n,INT_MAX),twor(n,INT_MAX),threer(n,INT_MAX);
        prevone = -1;
        prevtwo = -1;
        prevthree = -1;
        for(int i=n-1;i>=0;i--){
            if(colors[i]==1){
                oner[i] = 0;
                prevone = 1;
                if(prevtwo!=-1)     twor[i] = prevtwo, prevtwo++;
                if(prevthree!=-1)    threer[i] = prevthree, prevthree++;
            }else if(colors[i]==2){
                twor[i] = 0;
                prevtwo = 1;
                if(prevone!=-1)     oner[i] = prevone, prevone++;
                if(prevthree!=-1)    threer[i] = prevthree, prevthree++;
            }else{
                threer[i] = 0;
                prevthree = 1;
                if(prevone!=-1)     oner[i] = prevone, prevone++;
                if(prevtwo!=-1)    twor[i] = prevtwo, prevtwo++;
            }
        }
        
        int m = queries.size();
        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            int j = queries[i][0];
            int v = queries[i][1];
            if(v==1){
                int mini = min(onel[j],oner[j]);
                if(mini!=INT_MAX){
                    ans[i] = mini;
                }
            }else if(v==2){
                int mini = min(twol[j],twor[j]);
                if(mini!=INT_MAX){
                    ans[i] = mini;
                }
            }else{
                int mini = min(threel[j],threer[j]);
                if(mini!=INT_MAX){
                    ans[i] = mini;
                }
            }
        }
        return ans;
    }
};