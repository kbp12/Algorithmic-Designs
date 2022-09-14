/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> sch) {
        int n = sch.size();
        vector<Interval>arr;
        for(int i=0;i<n;i++){
            for(auto in:sch[i]){
                arr.push_back(in);
            }
        }
        sort(arr.begin(),arr.end(),[](Interval a, Interval b){
            return a. start<b.start;
        });
        vector<Interval>ans;
        int prev = INT_MIN;
        for(int i=0;i<arr.size();i++){
            int st = arr[i].start;
            if(st>prev and prev!=INT_MIN){
                Interval* inter = new Interval(prev,st);
                ans.push_back(*inter);
            }
            prev = max(prev,arr[i].end);
        }
        return ans;
    }
};