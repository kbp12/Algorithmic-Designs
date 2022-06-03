class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int j = s.length()-1, i=0, count = 0;
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
                continue;
            }
            int k = j;
            bool isSingle = true;
            while(k>i){
                if(s[k]==s[i]){
                    isSingle = false;
                    break;
                }
                k--;
            }
            if(isSingle){
                swap(s[i],s[i+1]);
                count++;
            }else{
                while(k<j){
                    swap(s[k],s[k+1]);
                    k++; count++;
                }
                i++; j--;
            }
        }
        return count;
    }
};