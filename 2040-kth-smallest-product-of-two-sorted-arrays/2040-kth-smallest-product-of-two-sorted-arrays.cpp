class Solution {
public:
    long long count(vector<int>& n1, vector<int>& n2, long long m) {
    long long cnt = 0;
    for (int p1 = 0, p2 = n2.size() - 1; p1 < n1.size(); ++p1) {
        while (p2 >= 0 && (long long)n1[p1] * n2[p2] > m)
            --p2;
        cnt += p2 + 1;
    }
    return cnt;
}
long long kthSmallestProduct(vector<int>& n1, vector<int>& n2, long long k) {
    auto lp = lower_bound(begin(n1), end(n1), 0), rp = lower_bound(begin(n2), end(n2), 0);
    vector<int> neg1(begin(n1), lp), neg2(begin(n2), rp);
    vector<int> pos1(lp, end(n1)), pos2(rp, end(n2));
    vector<int> pos1_r(rbegin(pos1), rend(pos1)), pos2_r(rbegin(pos2), rend(pos2));
    vector<int> neg1_r(rbegin(neg1), rend(neg1)), neg2_r(rbegin(neg2), rend(neg2)); 
    long long l = -10000000000, r = 10000000000;
    while (l < r) {
        long long m = (l + r - 1) / 2, cnt = 0;
        if (m >= 0)
            cnt = count(neg1_r, neg2_r, m) + count(pos1, pos2, m) 
                + neg1.size() * pos2.size() + neg2.size() * pos1.size();
        else
            cnt = count(pos2_r, neg1, m) + count(pos1_r, neg2, m);
        if (cnt < k) 
            l = m + 1;
        else
            r = m;
    }
    return l;
}
};