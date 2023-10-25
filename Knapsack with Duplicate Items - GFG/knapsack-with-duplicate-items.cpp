//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int val[],int wt[],int w,int n,vector<vector<int>> &dp)
    {
        if(w==0 || n==0)
            return 0;
        
        if(dp[w][n]!=-1)
            return dp[w][n];
            
        if(wt[n-1] <=w){
            return dp[w][n]=max(val[n-1] + solve(val,wt,w-wt[n-1],n,dp),solve(val,wt,w,n-1,dp));
        }
        else
            return dp[w][n]=solve(val,wt,w,n-1,dp);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(W+1,vector<int>(N+1,-1));
        return solve(val,wt,W,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends