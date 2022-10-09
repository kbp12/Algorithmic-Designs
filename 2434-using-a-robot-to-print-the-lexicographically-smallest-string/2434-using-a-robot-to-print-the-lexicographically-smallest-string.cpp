class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26,0);
        for(char ch:s){
            cnt[ch-'a']++;
        }
        stack<char>t;
        string ans="";  
        for(char ch:s){
            t.push(ch);
            cnt[ch-'a']--; 
            while(t.size()){
                char l = 'z';
                for(int j=0;j<26;j++){
                    if(cnt[j]){
                        l = 'a'+j;
                        break;
                    }
                }
                if(t.top()<=l){
                    ans+=t.top();
                    t.pop();
                }else{
                    break;
                }  
            }    
        }
        while(t.size()>0){
             ans+= t.top();
             t.pop();   
        }
        return ans;
      
    }
};