class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int j=0,k;
        for(int i=0;i<n;i++)
        {
            if(s[i] == ' ')
            {
                k=i-1;
                while(j<k)
                {
                    swap(s[j] , s[k]);
                    j++;k--;
                }
                j=i+1;
            }
        }
        k=n-1;
        while(j<k)
        {
            swap(s[j] , s[k]);
            j++;k--;
        }
        return s;
    }
};