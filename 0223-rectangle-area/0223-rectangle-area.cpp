class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax2-ax1) * abs(ay1-ay2);
        int area2 = abs(bx1-bx2) * abs(by1-by2);
        int overlap = 0, width = 0, height = 0;
        width = max(width , min(bx2 , ax2) - max(bx1 , ax1) );
        height = max(height , min(by2 , ay2) - max(ay1 , by1));
        overlap = width * height;
        return area1 + area2 - overlap;
    }
};