class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int r = 0, l = 0;
        for(int i=0;i<n;i++){
            r+=weights[i];
            l = max(l , weights[i]);
        }
        int ans = r;
        while(l<=r){
            int m = l+(r-l)/2 , cnt = 1, val = 0;
            for(int i=0;i<n;i++){
                if(val+weights[i] > m){
                    cnt++;
                    val = weights[i];
                }else{
                    val+=weights[i];
                }
            }
            if(cnt<=days){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};