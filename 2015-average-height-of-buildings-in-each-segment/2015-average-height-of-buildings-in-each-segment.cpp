class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
    vector<vector<int>> res;
    map<int, pair<int, int>> m;
    for (auto b : buildings) {
        m[b[0]].first += b[2];
        ++m[b[0]].second;
        m[b[1]].first -= b[2];
        --m[b[1]].second;
    }
    int h = 0, cnt = 0;
    for (auto [p, h_cnt] : m) {
        if (h)
            res.back()[1] = p;
        h += h_cnt.first;
        cnt += h_cnt.second;
        if (h && (res.empty() || res.back()[1] != p || res.back()[2] != h / cnt))
            res.push_back({p, p, h / cnt});
    }
    return res;
}
};