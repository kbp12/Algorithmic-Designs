class Solution {
public:
    int twoEggDrop(int n) {
        int ans = 0;
        int diff = 0;
        while(n>0){
            ans++;
            diff++;
            n-=diff;
        }
        return ans;
    }
};