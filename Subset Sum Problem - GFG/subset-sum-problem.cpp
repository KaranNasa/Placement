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
        vector<vector<int>> dp(sum+1,vector<int>(n+1,-1));
        return solve(arr,sum,arr.size(),dp);
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