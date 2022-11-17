class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool w = max(0 , min(rec2[2] , rec1[2]) - max(rec2[0] , rec1[0]));
        bool h = max(0 , min(rec2[3] , rec1[3]) - max(rec1[1] , rec2[1]));
        return w&h;
    }
};
