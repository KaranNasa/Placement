//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(vector<int> &arr,int sum,int n,vector<vector<int>> &dp)
    {
        if(sum<0 || n<0)
            return 0;
        if(sum==0 and n==0)
            return 1;
        
        if(dp[sum][n] != -1)
            return dp[sum][n];
        
        if(sum - arr[n-1] >= 0)
            return dp[sum][n]=solve(arr,sum-arr[n-1],n-1,dp) || solve(arr,sum,n-1,dp);
        else
            return dp[sum][n]=solve(arr,sum,n-1,dp);
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        // return solve(arr,sum,arr.size(),dp);
        for(int i=0;i<n+1;i++)
            dp[i][0]=true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if( j - arr[i-1] >= 0)
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends