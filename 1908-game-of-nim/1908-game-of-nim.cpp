class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int xorr = 0;
        for(auto pile:piles) xorr = xorr xor pile;
        return xorr;
    }
};