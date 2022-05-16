class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int m = 0,ans = 0;
        for(int i=0;i<n;i++){
            int v = flips[i]-1;
            m = max(m,v);
            if(m==i){
                ans++;
            }
        }
        return ans;
    }
};