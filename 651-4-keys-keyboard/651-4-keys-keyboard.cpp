class Solution {
public:
    int maxA(int N) {
        vector<int>best(N+1,0);
        for (int k = 1; k <= N; ++k) {
            best[k] = best[k-1] + 1;
            for (int x = 0; x < k-1; ++x)
                best[k] = max(best[k], best[x] * (k-x-1));
        }
        return best[N];
        
    }
};