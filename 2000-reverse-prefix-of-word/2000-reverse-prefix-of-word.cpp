class Solution {
public:
    string reversePrefix(string s, char ch) {
        int n = s.length();
        int i=0;
        while(i<n && s[i]!=ch)i++;
        if(i==0 || i==n) return s;
        string ans = s.substr(0,i+1);
        reverse(ans.begin(),ans.end());
        ans += s.substr(i+1,n-i-1);
        return ans;
    }
};