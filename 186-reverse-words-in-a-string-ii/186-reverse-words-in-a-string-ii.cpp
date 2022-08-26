class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(s[j]==' ' or j==n-1){
                int k = j-1;
                if(j==n-1) k++;
                while(i<k){
                    swap(s[i],s[k]);
                    i++; k--;
                }
                j++;
                i = j;
            }else{
                j++;
            }
        }
        i = 0, j = n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++; j--;
        }
        return;
    }
};