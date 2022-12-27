class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long max_sum = 0 , sum = 0, mod = 1e9+7;
        int pref = 0, suff = 0, max_pref = 0, max_suff = 0;
        for(int i=0;i<n;i++){
            pref+=arr[i];
            suff+=arr[n-1-i];
            max_pref = max(max_pref , pref);
            max_suff = max(max_suff , suff);
            sum = max(sum+arr[i] , (long long)arr[i]);
            max_sum = max(max_sum , sum);
        }
        if(k==1) return max_sum;
        long long ans = max_pref + max_suff + (long long)max(pref , 0) * (k-2);
        return max(max_sum , ans)%mod;
    }
};