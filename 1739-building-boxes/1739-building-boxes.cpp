class Solution {
public:
    int minimumBoxes(int n) {
        int sum = 0, i = 0, j = 0;
        while(sum < n) {
            j++;
            i+= j;
            sum += i;
        }
        if(sum == n) return i;
        sum-= i;
        i-= j;
        j= 0;
        while(sum < n) {
            j++;
            sum+= j;
        }
        return i+j;
    }
};