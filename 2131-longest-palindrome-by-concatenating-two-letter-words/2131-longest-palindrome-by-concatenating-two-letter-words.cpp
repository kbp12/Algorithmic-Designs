class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int>m;
        int mid = 0;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        
        int count = 0;
        int odd = 0;
        for(auto a:m){
            string temp = a.first;
            if(temp[0]!=temp[1]){
                reverse(temp.begin(),temp.end());
                if(m.find(temp)!=m.end()){
                    count+= 2*min(a.second,m[temp]);
                }
            }else{
                if(a.second%2 == 0)
                    count+= 2*a.second;
                
                else{
                    
                    odd = max(odd,a.second);
                    count  += 2*(a.second-1);
                }
            }
            
        }
        if(odd>0)
            count+=2;
        return count;
    }
};