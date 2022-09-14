class Solution {
public:
    bool findGameWinner(int n) {
        if((n-1)%6) return true;
        return false;
    }
};