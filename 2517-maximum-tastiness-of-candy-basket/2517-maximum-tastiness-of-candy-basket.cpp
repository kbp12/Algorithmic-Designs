class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin() , price.end());
        int l = 0, r = 1e9+1;
        int n = price.size() , res = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            int cnt = 1;
            int prev = price[0];
            for(int i=1;i<n;i++){
                if(price[i] - prev >= m){
                    cnt++;
                    prev = price[i];
                }
            }
            if(k<=cnt){
                res = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return res;
    }
};