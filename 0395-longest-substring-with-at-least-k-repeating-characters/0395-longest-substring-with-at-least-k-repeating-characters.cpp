class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxi = 0;
        unordered_set<char>temp_set;
        for(int i=0;i<n;i++) temp_set.insert(s[i]);
        maxi = temp_set.size();
        int ans = 0;
        for(int ch = 1; ch<= maxi; ch++){
            int chars = 0;
            unordered_map<char,int>umap;
            int i=0, j=0, res = 0;
            while(j<n){
                if(umap.find(s[j]) == umap.end() and chars<ch){
                    umap[s[j]]++;
                    chars++;
                }else{
                    if(umap.find(s[j]) == umap.end()) chars++;
                    umap[s[j]]++;
                    while(i<j and chars > ch){
                        if(umap[s[i]] == 1){
                            umap.erase(s[i]);
                            chars--;
                        }else{
                            umap[s[i]]--;
                        }
                        i++;
                    }
                }
                bool yes = true;
                for(auto it:umap){
                    if(it.second < k){
                        yes = false;
                        break;
                    }
                }
                if(yes){
                    res = max( res , j-i+1);
                }
                j++;
            }
            ans = max(ans , res);
        }
        return ans;
    }
};