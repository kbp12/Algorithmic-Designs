class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for(auto ch:magazine){
            a[ch-'a']++;
        }
        for(auto ch:ransomNote){
            a[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(a[i]<0) return false;
        }
        return true;
    }
};