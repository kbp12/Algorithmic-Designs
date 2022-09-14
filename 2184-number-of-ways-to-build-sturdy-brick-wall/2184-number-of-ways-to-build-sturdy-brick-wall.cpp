class Solution {
public:
    int dp[101][1024] = {};
int dfs_h(int h, int i, vector<vector<int>> &ids) {
    if (h == 0)
        return 1;
    if (dp[h][i] == 0)
        for (int j : ids[i])
            dp[h][i] = (dp[h][i] + dfs_h(h - 1, j, ids)) % 1000000007;
    return dp[h][i];
}
vector<int> dfs_w(int w, int width, vector<int>& bricks, int mask, vector<int> &masks) {
    if (w == width) 
        masks.push_back(mask);
    else {
        if (w)
            mask += (1 << (w - 1));
        for (int b : bricks)
            if (w + b <= width)
                dfs_w(w + b, width, bricks, mask, masks);
    }
    return masks;
}
int buildWall(int height, int width, vector<int>& bricks) {
    vector<int> masks = dfs_w(0, width, bricks, 0, vector<int>() = {});
    vector<vector<int>> ids(masks.size() + 1);
    for (int i = 0; i < masks.size(); ++i)
        for (int j = 0; j < masks.size(); ++j) {
            if (i == 0)
                ids[0].push_back(j + 1);
            if ((masks[i] & masks[j]) == 0)
                ids[i + 1].push_back(j + 1);
        }
    return dfs_h(height, 0, ids);
}
};