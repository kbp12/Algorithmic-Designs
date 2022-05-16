class Solution {
public:
    int flipLights(int n, int p) {
        if(n==0 || p==0) return 1;
        if(n==1) return 2;
        if(n==2){
            if(p==1) return 3;
            else return 4;
        }
        if(p==1) return 4;
        if(p==2) return 7;
        return 8;
    }
};