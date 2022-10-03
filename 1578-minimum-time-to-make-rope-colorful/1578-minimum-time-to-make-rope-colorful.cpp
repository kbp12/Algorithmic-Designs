class Solution {
public:
    int minCost(string s, vector<int>& time) {
        int n = time.size();
        int ans = 0, i = 1;
        int count = time[0], maxi = time[0];
        while(i<n){
            int j = i;
            while(i<n and s[i]==s[i-1]){
                count+=time[i];
                maxi = max(maxi,time[i]);
                i++;
            }
            ans+=(count-maxi);
            if(i<n){
                count = time[i];
                maxi = time[i];
            }
            if(i==j) i++;
        }
        return ans;
    }
};