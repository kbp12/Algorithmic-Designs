class Solution {
public:
    int maximumScore(vector<int>& sc, vector<vector<int>>& edges) {
    int res = -1;
    vector<vector<int>> al(sc.size());
    for (auto &e : edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    for(auto &l : al) {
        partial_sort(begin(l), begin(l) + min((int)l.size(), 3), end(l), [&](int i, int j){ return sc[i] > sc[j]; });
        l.resize(min((int)l.size(), 3));
    }
    for (auto &e : edges)
        for (int in : al[e[0]])
            for (int jn : al[e[1]])
                if (in != e[1] && jn != e[0] && in != jn)
                    res = max(res, sc[e[0]] + sc[e[1]] + sc[in] + sc[jn]);
    return res;
    }
};