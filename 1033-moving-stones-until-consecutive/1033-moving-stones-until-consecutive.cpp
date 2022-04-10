class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int>arr(3);
        arr[0] = a, arr[1] = b, arr[2] = c;
        sort(arr.begin(), arr.end());
        int mini,maxi;
        if(arr[1]-arr[0]==1 && arr[2]-arr[1]==1){
            mini = 0; maxi = 0;
        }else if(arr[1]-arr[0]==2 || arr[1]-arr[0]==1 || arr[2]-arr[1]==2 || arr[2]-arr[1]==1){
            mini = 1;
            maxi = arr[2]-arr[0]-2;
        }else{
            mini = 2;
            maxi = arr[2]-arr[0]-2;
        }
        return {mini,maxi};
    }
};