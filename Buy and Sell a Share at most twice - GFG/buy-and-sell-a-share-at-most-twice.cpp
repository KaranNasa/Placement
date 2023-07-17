//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int solve(int index,int buy,int n,int trans,vector<int> &price,vector<vector<vector<int>>> &dp)
{
    if(index==n || trans==0)
        return 0;
    
    if(dp[index][buy][trans]!=-1)
        return dp[index][buy][trans];
    
    if(buy){
        return dp[index][buy][trans]=max(-price[index]+solve(index+1,0,n,trans,price,dp),solve(index+1,1,n,trans,price,dp));
    }
    else{
        return dp[index][buy][trans]=max(price[index]+solve(index+1,1,n,trans-1,price,dp),solve(index+1,0,n,trans,price,dp));
    }
}

int maxProfit(vector<int>&price){
    //Write your code here..
    
    int n=price.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    // return solve(0,1,n,2,price,dp);
    
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<2;buy++){
            for(int trans=1;trans<=2;trans++){
                if(buy){
                    dp[index][buy][trans]=max(-price[index]+dp[index+1][0][trans],dp[index+1][1][trans]);
                }
                else{
                    dp[index][buy][trans]=max(price[index]+dp[index+1][1][trans-1],dp[index+1][0][trans]);
                }
            }
        }
    }
    return dp[0][1][2];
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends