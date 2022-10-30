class Solution {
public:
    string oddString(vector<string>& words) {
        map<string,vector<int>>mpp;
        int n = words[0].size();
        for(auto w:words){
            
            vector<int>v(n-1);
            for(int i=1;i<n;i++){
                v[i-1] = ((w[i]-'a') - (w[i-1]-'a'));
            }
            mpp[w] = v;
        }
        for(auto it:mpp){
            vector<int>temp = it.second;
            int count = 0;
            for(auto word:words){
                int n = word.size();
                vector<int>v(n-1);
                for(int i=1;i<n;i++){
                    v[i-1] = (word[i]-'a') - (word[i-1]-'a');
                }
                if(temp == v){
                    count++;
                }
            }
            if(count == 1) return it.first;
        }
        return " ";
    }
};