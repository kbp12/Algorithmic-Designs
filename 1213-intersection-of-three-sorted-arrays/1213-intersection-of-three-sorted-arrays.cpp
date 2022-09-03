class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        set<int>s;
        for(auto n:arr1){
            s.insert(n);
        }
        set<int>s2;
        for(auto n:arr2){
            if(s.find(n)!=s.end()){
                s2.insert(n);
            }
        }
        set<int>s3;
        for(auto n:arr3){
            if(s2.find(n)!=s2.end()){
                s3.insert(n);
            }
        }
        return vector<int>(s3.begin(),s3.end());
    }
};