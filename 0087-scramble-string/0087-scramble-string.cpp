class Solution {
public:
    map<pair<string,string>,bool>mpp;
    
    bool check(string & s1, string & s2){
        int cnt[26] = {0};
        for(auto & ch:s1) cnt[ch-'a']++;
        for(auto & ch:s2) cnt[ch-'a']--;
        for(int i=0;i<26;i++){
            if(cnt[i]!=0) return false;
        }
        return true;
    }
    
    bool solve(string s1 , string s2){
        int n = s1.size();
        if(n==1) return s1 == s2;
        if(mpp.count({s1,s2}))
            return mpp[{s1,s2}];
        for(int i=0;i<n-1;i++){
            string a = s1.substr(0, i+1);
            string b = s1.substr(i+1);
            string c = s2.substr(0, i+1);
            string d = s2.substr(i+1);
            string e = s2.substr(n-i-1);
            string f = s2.substr( 0 , n-i-1);
            if(check(a , c) and check(b , d) and solve(a , c) and solve( b ,d)){
                mpp[{s1,s2}] = true;
                return true;
            }
            if(check(a , e) and check(b ,f) and solve(a,e) and solve(b , f)){
                mpp[{s1 ,s2}] = true;
                return true;
            }
        }
        mpp[{s1 , s2}] = false;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        return solve(s1 ,s2);
    }
};