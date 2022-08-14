class Solution {
public:
    int permutation(int m, int n) {
        return n == 0 ? 1 : permutation(m, n - 1) * (m - n + 1);
    }
    int countSpecialNumbers(int N) {
        vector<int> digit;
        for (int i = N + 1; i > 0; i /= 10) {
            digit.push_back(i % 10);
        }
        reverse(digit.begin(), digit.end());
        
        int result = 0;
        int n = digit.size();
        for (int i = 1; i < n; i++) {
            result += 9 * permutation(9, i - 1);
        }
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            int dig = digit[i];
            int j = 0;
            if(i==0) j++;
            for ( ; j < dig; j++) {
                if (seen.find(j) == seen.end()) {
                    result += permutation(9-i, n - i - 1);
                }
            }
            if (seen.find(digit[i]) != seen.end()) {
                break;
            }
            seen.insert(digit[i]);
        }
        return result;
    }
};