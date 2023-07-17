//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int index,int buy,int k,int n,int A[],vector<vector<vector<int>>> &dp)
    {
        if(index==n || k==0)
            return 0;
        
        if(dp[index][buy][k]!=-1)
            return dp[index][buy][k];
            
        if(buy){
            return dp[index][buy][k]=max(-A[index]+solve(index+1,0,k,n,A,dp),solve(index+1,1,k,n,A,dp));
        }
        else{
            return dp[index][buy][k]=max(A[index]+solve(index+1,1,k-1,n,A,dp),solve(index+1,0,k,n,A,dp));
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        
        return solve(0,1,K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends