class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u'){
                idx.push_back(i);
            }else if(s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
                idx.push_back(i);
            }
        }
        int i=0,j=idx.size()-1;
        while(i<j){
            swap(s[idx[i]] , s[idx[j]]);
            i++,j--;
        }
        return s;
    }
};