//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<int>big(26,0),small(26,0);
        for(int i=0;i<n;i++){
            if(str[i]>='a' and str[i]<='z'){
                small[str[i]-'a']++;
            }else{
                big[str[i]-'A']++;
            }
        }
        for(int i=0;i<n;i++){
            if(str[i]>='a' and str[i]<='z'){
                for(int j=0;j<26;j++){
                    if(small[j]){
                        str[i] = 'a'+j;
                        small[j]--;
                        break;
                    }
                }
            }else{
                for(int j=0;j<26;j++){
                    if(big[j]){
                        str[i] = 'A'+j;
                        big[j]--;
                        break;
                    }
                }
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends