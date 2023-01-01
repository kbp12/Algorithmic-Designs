class Solution {
public:
    int minimumPartition(string s, int k) {
        long long n = s.size(), temp = 0, cnt = 1;
        for(int i=0;i<n;i++){
            temp = temp*10+(s[i]-'0');
            if(s[i]-'0' > k) return -1;
            if(temp>k){
                temp = (s[i]-'0');
                cnt++;
            }
        }
        return cnt;
    }
};