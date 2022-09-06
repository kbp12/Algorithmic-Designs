class Solution {
public:
    int numberOfPatterns(int m, int n) {
    array<int, 5120> cache;
    cache.fill(-1);
    return numberOfPatterns_recur(max(m, 0), min(n, 9), 0, 0, 4, cache);
}

int numberOfPatterns_recur( int m, int n, int len, int visited, int last, 
                            array<int, 5120>& cache ) {
    if (n == len) return 1;
    
    int code = visited + (last << 9); //code key for current state
    if (cache[code]>=0) return cache[code];
    
    int count = (m <= len);
    for (int k = 0; k < 9; ++k) {
        if (valid(k, visited, last)) 
            count += numberOfPatterns_recur(m, n, len+1, visited | (1 << k), 
                                            k, cache);
    }
    cache[code] = count;
    return count;
}

inline bool valid(int cur, int visited, int last) {
    if (is_set(visited, cur)) return false; //check if visited
    
    int sum_x = last/3 + cur/3;
    int sum_y = last%3 + cur%3;
    if (visited == 0 || sum_x % 2 || sum_y %2) return true; //check if cross some key
    
    int mid_point = sum_x/2*3 + sum_y/2;
    return is_set(visited, mid_point); //check if mid point already set
}

inline bool is_set(int visited, int digit) {
    return visited & (1 << digit);
}
};