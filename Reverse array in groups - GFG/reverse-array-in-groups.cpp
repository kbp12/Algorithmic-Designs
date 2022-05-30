// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        vector<long long>temp(n);
        if(k==1) return;
        int t = n/k;
        for(int c=0;c<t;c++){
            int l = k*c;
            int r = k*(c+1)-1;
            while(l<r){
                swap(arr[l],arr[r]); l++; r--;
            }
        }
        if(k*t<n){
            int l = k*t, r = n-1;
            while(l<r){
                swap(arr[l],arr[r]); l++; r--;
            }
        }
        return;
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends