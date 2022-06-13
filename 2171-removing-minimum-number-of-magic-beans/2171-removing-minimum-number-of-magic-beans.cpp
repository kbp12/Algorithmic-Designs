class Solution {
public:
    long long minimumRemoval(vector<int>& b) {
        sort(b.begin(),b.end());
        int n = b.size();
        long long sum = 0,ans;
        for(int i=0;i<n;i++) sum+=b[i];
        ans = sum;
        for(int i=0;i<n;i++){
            long long temp = n-i;
            temp*=b[i];
            ans = min(ans,sum-temp);
        }
        return ans;
    }
};