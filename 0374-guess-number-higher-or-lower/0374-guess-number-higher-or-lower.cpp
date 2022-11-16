/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n==1) return 1;
        if(n==INT_MAX) return INT_MAX;
        int a = 1;
        int b = INT_MAX-1;
        while(true){
            long long s = a;
            s+=b;
            int m = (s)/2;
            int c = guess(m);
            if(c==0) return m;
            
            if(c==-1){
                b = m-1;
            }else{
                a = m+1;
            }
        }
        return 0;
    }
};