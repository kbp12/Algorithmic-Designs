class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen<tlen) return "";
        int tarr[256] = {0};
        int sarr[256] = {0};
        for(int i=0;i<tlen;i++)
            tarr[t[i]]++;
        
        int start = 0, count = 0, start_idx = -1, len = INT_MAX;
        for(int i=0;i<slen;i++){
            sarr[s[i]]++;
            if(tarr[s[i]]>=sarr[s[i]])
                count++;
            
            if(count == tlen){
                while(sarr[s[start]]>tarr[s[start]] || tarr[s[start]]==0){
                    sarr[s[start]]--;
                    start++;
                }
                
                if(i-start+1 < len){
                    len = i-start+1;
                    start_idx = start;
                }
            }
        }
        if(start_idx == -1) return "";
        return s.substr(start_idx,len);
    }
};