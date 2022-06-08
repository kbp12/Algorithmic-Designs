class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int pos = -1;
        int  n = arr.size();
        if(n==1) return arr;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                pos = i;
            }
        }
        if(pos==-1) return arr;
        int mini = pos+1;
        for(int j=pos+1;j<n;j++){
            if(arr[j]<arr[pos] && arr[j]>arr[mini]){
                mini = j;
            }
        }
        swap(arr[pos],arr[mini]);
        return arr;
    }
};