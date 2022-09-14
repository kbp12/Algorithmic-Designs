class Solution {
public:
    int dp[101][1024] = {};
int dfs_h(int h, int prev, const vector<int>& masks) {
    if (h == 0)
        return 1;
    if (dp[h][prev] == 0)
        for (int mask : masks)
            if ((mask & prev) == 0)
                dp[h][prev] = (dp[h][prev] + dfs_h(h - 1, mask, masks)) % 1000000007;
    return dp[h][prev];
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
    return dfs_h(height, 0, dfs_w(0, width, bricks, 0, vector<int>() = {}));
}
};