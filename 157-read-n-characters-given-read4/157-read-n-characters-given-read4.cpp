/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ans = 0;
        int a = 0, d = 0;
        while(a<n){
            d = min(4,n-a);
            int temp = read4(buf);
            buf+=d;
            a+=d;
            ans+=min(d,temp);
        }
        return ans;
    }
};