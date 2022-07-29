class Solution {
public:
    string reverseVowels(string s) {
        set<int>idx;
        int n = s.length();
        vector<char>vowel;
        for(int i=0;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                idx.insert(i);
                vowel.push_back(s[i]);
            }
        }
        int k = idx.size(),j=0;
        for(int i=n-1;i>=0;i--){
            if(j<k and idx.find(i)!=idx.end()){
                s[i] = vowel[j];
                j++;
            }
        }
        return s;
    }
};