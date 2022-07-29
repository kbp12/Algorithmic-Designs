class Solution {
public:
    bool isPerfectSquare(int num) {
        long long a = 1;
        while(a*a<num){
            a++;
        }
        if(a*a==num) return true;
        a++;
        return a*a==num;
    }
};