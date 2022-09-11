class Solution {
public: 
    const static int N = 100001;
    array<int, 2*N> seg{};
    
    void update(int pos, int val){ // update max
        pos += N;
        seg[pos] = val;
 
        while (pos > 1) {
            pos >>= 1;
            seg[pos] = max(seg[2*pos], seg[2*pos+1]);
        }
    }
 
    int query(int lo, int hi){ // query max [lo, hi)
        lo += N;
        hi += N;
        int res = 0;
 
        while (lo < hi) {
            if (lo & 1) {
                res = max(res, seg[lo++]);
            }
            if (hi & 1) {
                res = max(res, seg[--hi]);
            }
            lo >>= 1;
            hi >>= 1;
        }
        return res;
    }
    
    int lengthOfLIS(vector<int>& A, int k) {
        int ans = 0;
        for (int i = 0; i < size(A); ++i){
            int l = max(0, A[i]-k);
            int r = A[i];
            int res = query(l, r) + 1; // best res for the current element
            ans = max(res, ans);
            update(A[i], res); // and update it here
        }
        
        return ans;
    }
};