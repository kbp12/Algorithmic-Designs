class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),[](string s1, string s2){
            string id1 = "";
            int i=0;
            while(i<s1.size() and s1[i]!=' '){
                id1+=s1[i]; i++;
            }
            bool isdig1 = false;
            string str1 = "";
            if(s1[i+1]>='0' and s1[i+1]<='9'){
                isdig1 = true;
            }else{
                str1 = s1.substr(i+1);
            }
            i = 0;
            string id2 = "",str2 = "";
            while(i<s2.size() and s2[i]!=' '){
                id2+=s2[i]; i++;
            }
            bool isdig2 = false;
            if(s2[i+1]>='0' and s2[i+1]<='9'){
                isdig2 = true;
            }else{
                str2 = s2.substr(i+1);
            }
            if(isdig1==false and isdig2==false){
                if(str1!=str2) return str1<str2;
                return id1<id2;
            }
            if(isdig1==false){
                return true;
            }
            if(isdig2==false){
                return false;
            }
            return false;
        });
        return logs;
    }
};