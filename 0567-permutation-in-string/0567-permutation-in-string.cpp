class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2) return false;
        int arr1[26],arr2[26];
        fill(arr1,arr1+26,0);
        fill(arr2,arr2+26,0);
        for(int i=0;i<n1;i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        bool toreturn = true;
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                toreturn = false;
                break;
            }
        }
        if(toreturn) return true;
        for(int i=n1;i<n2;i++){
            toreturn = true;
            arr2[s2[i]-'a']++;
            arr2[s2[i-n1]-'a']--;
            for(int i=0;i<26;i++){
                if(arr1[i]!=arr2[i]){
                    toreturn = false;
                    break;
                }
            }
            if(toreturn) return true;
        }
        return false;
    }
};