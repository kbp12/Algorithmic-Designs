// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    
    bool solve(int i, int n, int k, int a[], int total[], int sum){
        if(i==n){
            return true;
        }
        for(int j=0;j<k;j++){
            if(total[j]!=0){
                if(total[j]+a[i]<=sum){
                    total[j]+=a[i];
                    if(solve(i+1,n,k,a,total,sum)){
                        return true;
                    }
                    total[j]-=a[i];
                }
            }else{
                if(total[j]+a[i]<=sum){
                    total[j]+=a[i];
                    if(solve(i+1,n,k,a,total,sum)){
                        return true;
                    }
                    total[j]-=a[i];
                }
                break;
            }
        }
        return false;
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         if(k==1) return true;
         if(k>n) return false;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k!=0) return false;
         sum = sum/k;
         int total[k];
         for(int i=0;i<k;i++) total[i] = 0;
         if(solve(0,n,k,a,total,sum)){
             return true;
         }
         return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends