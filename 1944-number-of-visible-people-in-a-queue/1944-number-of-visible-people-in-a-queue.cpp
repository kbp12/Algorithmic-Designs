class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> temp;
    for (int i = heights.size() - 1; i >= 0; --i) {
        int h = heights[i], c = 0;
        for (; !temp.empty() && temp.back() < h; ++c)
            temp.pop_back();
        if(temp.size())
            heights[i] = c+1;
        else
            heights[i] = c;
        temp.push_back(h);
    }
    return heights;
    }
};