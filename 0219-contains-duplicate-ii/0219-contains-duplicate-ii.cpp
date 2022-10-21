class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        int n = a.size() , i=0 , st = 0;
        unordered_set<int>s;
        if(k==0)    return false;
        while(i<n){
            if(i-st<=k){
                if(s.find(a[i])!= s.end())    return true;
                else    s.insert(a[i]);
                i++;
            }else{
                s.erase(a[st]);
                st++;
            }
        }
        return false;
    }
};