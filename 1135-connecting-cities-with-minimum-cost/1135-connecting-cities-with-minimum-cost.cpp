class Solution {
public:
    vector<int> parent;
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return (a[2] < b[2]);
    }
    
    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), comp);
        parent.resize(N+1, 0);
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        int res = 0, count = 1;
        for (auto& c : connections) {
            int rx = find(c[0]), ry = find(c[1]);
            if (rx != ry) {
                res += c[2];
                parent[ry] = rx;
                count++;
            }
            if (count == N) return res;
        }
        return -1;
    }
};