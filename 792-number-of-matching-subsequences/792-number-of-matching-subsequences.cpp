class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        int l1 = s.length();
        map<string,int> m; 
        for (auto word : words){
            int l2 = word.length(); 
            int j = 0;
            if (m.find(word) == m.end()){ 
               for (int i=0;i<l1 && j<l2;i++){   
                    if (s[i]==word[j]){
                        j++;
                    }
                }
                ans+=(j==l2);
                m[word] = (j==l2);
            }
            else{
                ans+= m[word];
            }
            
            
        }
        return ans;
    }
};