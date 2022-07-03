class Solution {
public:
    string decodeMessage(string s, string mess) {
        map<char,char>mpp;
        char ch = 'a';
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end() && s[i]!=' '){
                mpp[s[i]] = ch;
                ch++;
            }
        }
        string ans ="";
        for(int i=0;i<mess.size();i++){
            if(mess[i]==' ')
                ans+=' ';
            else 
                ans+= mpp[mess[i]];
        }
        return ans;
    }
};