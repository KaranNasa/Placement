//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int index,int buy,vector<long long> &prices,int n,vector<vector<long long>> &dp)
    {
        if(index>=n)
            return 0;
        
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        if(buy){
            return  dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,n,dp),solve(index+1,1,prices,n,dp));
        }
        else{
            return  dp[index][buy]=max(prices[index]+solve(index+2,1,prices,n,dp),solve(index+1,0,prices,n,dp));
        }
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n+2,vector<long long>(2,0));
        // return solve(0,1,prices,n,dp);
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }
                else{
                    dp[index][buy]=max(prices[index]+dp[index+2][1],dp[index+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends