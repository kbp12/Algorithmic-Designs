class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
        }
        sort(words.begin(),words.end());
        int ans = words[n-1].length();
        for(int i=n-2;i>=0;i--){
            int a = words[i].length();
            int b = words[i+1].length();
            if(a<=b){
                int j=0,k=0;
                while(j<a && words[i][j]==words[i+1][k]){
                    j++; k++;
                }
                if(j!=a){
                    ans+= a+1;
                }
            }else{
                ans+= a+1;
            }
        }
        return ans+1;
    }
};