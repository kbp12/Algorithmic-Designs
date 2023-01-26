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
        vector<int> small;
        vector<int> big;
        //unordered_map<int,int> m;
        for(int i=0;i<str.size();i++){
            if(str[i]<='Z' and str[i]>='A'){
                big.push_back(str[i]-'A');
                //m[i]++;
            }
            else{
                small.push_back(str[i]-'a');
            }
        }
        
        sort(big.begin(),big.end());
        sort(small.begin(),small.end());
        
        int j=0,k=0;
        
        for(int i=0;i<str.size();i++){
            if(str[i]<='Z' and str[i]>='A'){
                str[i]=big[j]+'A';
                j++;
            }
            else{
                str[i]=small[k]+'a';
                k++;
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