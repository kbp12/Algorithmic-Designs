class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(int N) {
        count = 0;
        for (int i = 0; i < N; ++i){
            parent.push_back(-1);
            rank.push_back(0);
        }
    }

    bool isValid(int i) const {
        return parent[i] >= 0;
    }

    void setParent(int i) {
        if(parent[i]!=-1) return;
        parent[i] = i;
        count++;
    }

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void Union(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
            else {
                parent[rooty] = rootx; rank[rootx] += 1;
            }
            count--;
        }
    }

    int getCount() const {
        return count;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        UnionFind uf (m * n);

        for (auto& pos : positions) {
            int r = pos[0];
            int c = pos[1];
            vector<int> overlap;
            if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
            if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
            if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
            if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

            int index = r * n + c;
            uf.setParent(index);
            for (auto i : overlap) uf.Union(i, index);
            ans.push_back(uf.getCount());
        }

        return ans;
    }
};