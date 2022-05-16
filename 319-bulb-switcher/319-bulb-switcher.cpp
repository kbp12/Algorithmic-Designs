class Solution {
public:
    int bulbSwitch(int n) {
        int i=0;
        while(i*i<=n){i++;}
        return i-1;
    }
};