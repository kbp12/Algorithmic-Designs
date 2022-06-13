class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        long long sum = 0;
        for(int i=0;i<n;i++) sum+= a[i];
        long long ans = sum;
        long long prev = 0;
        for(int i=0;i<n;i++){
            long long temp = (n-i);
            temp*=a[i];
            ans = min(ans,prev+sum-temp);
            prev+=a[i];
            sum-=a[i];
        }
        return ans;
    }
};