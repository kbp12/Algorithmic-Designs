class Solution {
public:
    int numberOfSteps(int n) {
        int c = 0;
        while(n!=0){
            if(n%2)n--;
            else n = n/2;
            c++;
        }
        return c;
    }
};