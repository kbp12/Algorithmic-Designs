class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        k--;
        int n = w.size();
        vector <long long> v;
        for(int i = 0; i + 1 < n; ++i)
            v.push_back(w[i] + w[i + 1]);
        sort(v.begin(), v.end());
        long long mn = 0;
        for(int i = 0; i < k; ++i)
            mn += v[i];
        reverse(v.begin(), v.end());
        long long mx = 0;
        for(int i = 0; i < k; ++i)
            mx += v[i];
        return mx - mn;
    }
};