//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int solve(string s1,string s2,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return 0;
            
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s1[n-1] == s2[m-1])
            return dp[n][m]=1+solve(s1,s2,n-1,m-1,dp);
        else
            return dp[n][m]=max(solve(s1,s2,n-1,m,dp),solve(s1,s2,n,m-1,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        
        string s1=A;
        reverse(A.begin(),A.end());
        string s2=A;
        int n=A.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s1,s2,n,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends