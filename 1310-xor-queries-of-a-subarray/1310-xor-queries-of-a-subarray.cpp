class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int>xorr(n+1,0);
        for(int i=1;i<=n;i++){
            xorr[i] = xorr[i-1] xor arr[i-1];
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            ans[i] = xorr[queries[i][1]+1] xor xorr[queries[i][0]];
        }
        return ans;
    }
};