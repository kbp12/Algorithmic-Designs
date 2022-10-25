class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        // All courses numbers are shifted down by 1
        // Bit representation and bit manipulation is heavily used.
        const int nStates = 1<<n; // All subsets of n courses, bit representation
        vector<int> dp(nStates, INT_MAX); // dp[i]: least semesters to finish courses of bit pattern i
        vector<int> pre(n); // [TRICK] pre[i]: prerequisites of i-th course, bit representation 
        // Initialize pre array
        for (auto& dep: dependencies) {
            pre[dep[1]-1] = pre[dep[1]-1] | (1<<(dep[0]-1));
        }
        // Dynamic Processing
        dp[0] = 0;
        vector<int> idx(n); // Candidates indexes
        for (int i = 0; i < nStates; i++) { // Enumerate all subsets (courses already taken)
            if (dp[i] == INT_MAX) 
                continue;
            int candidates = 0; // Courses that are ready and not taken yet, bit representation
            int nCandidates = 0; // Number of these candidate courses.
            for (int j = 0; j < n; j++) { // Check all courses
                if ((i>>j) & 1) // If course j already taken, ignore it.
                    continue;
                if ((i & pre[j]) == pre[j]) { // [TRICK] If all of course j's prerequistes are already taken.
                    idx[nCandidates] = j;
                    nCandidates ++;
                    candidates = candidates | (1<<j);
                }    
            }
            if (nCandidates <= k) { 
                // Take all of these courses in one semester.
                dp[i|candidates] = min(dp[i|candidates], dp[i]+1); 
            } else { 
                // Enumerate subsets of size k, Gosper's Hack. 
                for (int s = (1<<k)-1; s < (1<<nCandidates);) {
                    // Map bit-pattern "subsets of candidates" to bit-pattern "subsets of all courses"  
                    int subsetk = 0;
                    for (int j = 0; j < nCandidates; j++) {
                        if ((s >> j) & 1)
                            subsetk = subsetk | (1 << idx[j]);
                    }
                    dp[i|subsetk] = min(dp[i|subsetk], dp[i]+1);
                    
                    int x = s & -s; // WARNING: bit manipulation magic.
                    int y = s + x;  // WARNING: bit manipulation magic.
                    s = (((s & ~y) / x) >> 1) | y; // WARNING: bit manipulation magic.
                }
            }
        }
        return dp[nStates-1];
    }
};