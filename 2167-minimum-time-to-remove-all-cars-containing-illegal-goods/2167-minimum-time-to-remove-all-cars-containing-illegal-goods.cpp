class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int>left(n), right(n);
        int j=0, k= n-1;
        left[0] = s[0]-'0'; right[n-1] = s[n-1]-'0';
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                left[i] = left[i-1];
            }else{
                left[i] = min(i+1, left[j]+2);
                j=i;
            }
            if(s[n-1-i]=='0'){
                right[n-1-i] = right[n-i];
            }else{
                right[n-1-i] = min(i+1,right[k]+2);
                k = n-1-i;
            }
        }
        int ans = right[0];
        for(int i=0;i<n-1;i++){
            ans = min(ans,left[i]+right[i+1]);
        }
        return ans;
    }
};