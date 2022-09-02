class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        char a = '1', b = '2';
        int c = 0, d = 0;
        int ans = 0;
        int l = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==a or a=='1'){
                a = s[i];
                l++;
            }else if(s[i]==b or b=='2'){
                b = a;
                d = c;
                c = i;
                a = s[i];
                l++;
            }else{
                l = i-c+1;
                b = a;
                d = c;
                c = i;
                a = s[i];
            }
            ans = max(ans,l);
        }
        return ans;
    }
};