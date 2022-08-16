class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> line(50001), res(paint.size());
    for (int i = 0; i < paint.size(); ++i) {
        int start_i = paint[i][0], end_i = paint[i][1];
        while (start_i < end_i) {
            int jump = max(start_i + 1, line[start_i]);
            res[i] += line[start_i] == 0;
            line[start_i] = max(line[start_i], end_i); // compression
            start_i = jump;
        }
    }
    return res;
    }
};