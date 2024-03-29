class Solution {
public:
    bool isReachable(int x, int y) {
        int g = gcd(x, y);
        while (g % 2 == 0)
            g /= 2;
        return g == 1;
    }
};
 