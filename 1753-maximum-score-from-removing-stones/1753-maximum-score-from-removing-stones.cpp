class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int arr[3];
        arr[0] =a, arr[1] =b, arr[2] =c;
        sort(arr, arr+3);
        if(arr[0]+arr[1]<=arr[2]) return arr[0]+arr[1];
        int t = arr[2]-arr[1];
        arr[0] -= t;
        return t+2*(arr[0]/2)+ arr[1]-(arr[0]/2);
    }
};