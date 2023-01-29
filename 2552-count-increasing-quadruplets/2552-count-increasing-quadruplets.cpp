class Solution {
public:
    long long countQuadruplets(vector<int>& a) {
        int n = a.size();
        vector <vector <long long> > dp0(n, vector <long long> (n + 2, 0));
        
        vector <vector <long long> > dp1(n, vector <long long> (n + 2, 0));
        
        for(int i = 0; i < n; ++i){
            if(i > 0){
                for(int j = 0; j <= n + 1; ++j)
                    dp0[i][j] = dp0[i - 1][j];
            }
            for(int j = a[i]; j <= n + 1; ++j)
                dp0[i][j]++;
        }
        
        for(int i = n - 1; i >= 0; --i){
            if(i + 1 < n){
                for(int j = 0; j <= n + 1; ++j)
                    dp1[i][j] = dp1[i + 1][j];
            }
            for(int j = 0; j <= a[i]; ++j)
                dp1[i][j]++;
        }
        
        long long ans = 0;
        
        for(int j = 1; j < n; ++j)
            for(int k = j + 1; k + 1 < n; ++k)
                if(a[k] < a[j])
                    ans += dp0[j - 1][a[k] - 1] * dp1[k + 1][a[j] + 1];
        
        return ans;
    }
};