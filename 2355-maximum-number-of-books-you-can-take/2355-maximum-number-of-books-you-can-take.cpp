class Solution {
public:
    long long ssum(long long l, int cnt) {
    return (l * (l + 1) - (l > cnt ? (l - cnt) * (l - cnt + 1) : 0)) / 2;
}
long long maximumBooks(vector<int>& b) {
    vector<int> ms;
    long long cur = 0, res = 0;
    for (int i = 0; i < b.size(); ++i) {
        while (!ms.empty() && b[i] - b[ms.back()] < i - ms.back()) {
            int j = ms.back(); ms.pop_back();
            cur -= ssum(b[j], ms.empty() ? j + 1: j - ms.back());
        }
        cur += ssum(b[i], ms.empty() ? i + 1 : i - ms.back());
        ms.push_back(i);
        res = max(cur, res);
    }
    return res;
}
};