//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int solve(int n,vector<int> &dp)
    {
        if(n==0 || n==1)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
            
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int nthFibonacci(int n){
        // code here
        vector<int> dp(n+1,-1);
        int mod=1e9+7;
        // return solve(n,dp)%1000000007;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        return dp[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends