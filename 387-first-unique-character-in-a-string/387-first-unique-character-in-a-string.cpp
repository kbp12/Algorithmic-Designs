class Solution {
public:
    int firstUniqChar(string s) {
        set<int>sett;
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(mpp.find(ch)!=mpp.end()){
                if(sett.find(mpp[ch])!=sett.end())
                    sett.erase(sett.find(mpp[ch]));
            }else{
                sett.insert(i);
                mpp[ch] = i;
            }
        }
        if(sett.size()) return *sett.begin();
        return -1;
    }
};