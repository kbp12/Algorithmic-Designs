class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0 , l = 0, r = n-1 , m;
        while(l<=r){
            m = l + (r - l)/2;
            if(citations[m] >= n-m){
                ans = n-m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};