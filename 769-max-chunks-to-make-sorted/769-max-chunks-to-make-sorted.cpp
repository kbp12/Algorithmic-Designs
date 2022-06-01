class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int>v = arr;
        sort(v.begin(),v.end());
        set<int>s1,s2;
        int chunks = 0;
        for(int i=0;i<n;i++){
            s1.insert(arr[i]);
            s2.insert(v[i]);
            if(s1==s2) chunks++;
        }
        return chunks;
    }
};