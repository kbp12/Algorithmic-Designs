class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(n!=1){
            int m = s.length();
            int i = 0;
            string s2 = "";
            while(i<m){
                int c = 1;
                int j = i+1;
                while(j<m && s[j]==s[i]){
                    c++; j++;
                }
                string s3 = to_string(c);
                s2+=s3 + s[i];
                i=j;
            }
            s=s2;
            n--;
        }
        return s;
    }
};