class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>m;
        for(auto a:arr){
            m[a]++;
        }
        vector<int>v;
        for(auto it:m){
            v.push_back(it.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int c = 0;
        for(int i=0;i<v.size();i++){
            c+= v[i];
            if(c>=(n/2)) return i+1;
        }
        return n/2;
    }
};