//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int index,int buy,vector<long long > &prices,int n,int fee,vector<vector<long long>> &dp)
    {
        if(index==n)
            return 0;
        
        if(dp[index][buy]!=-1)
            return dp[index][buy];
        
        if(buy){
            return dp[index][buy]=max(-prices[index]+solve(index+1,0,prices,n,fee,dp),solve(index+1,1,prices,n,fee,dp));
        }
        else{
            return dp[index][buy]=max(prices[index]-fee+solve(index+1,1,prices,n,fee,dp),solve(index+1,0,prices,n,fee,dp));
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        // return solve(0,1,prices,n,fee,dp);
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }
                else{
                    dp[index][buy]=max(prices[index]-fee+dp[index+1][1],dp[index+1][0]);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends