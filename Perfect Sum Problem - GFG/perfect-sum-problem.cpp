//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int dp[1002][1002];
	int mod=1e9+7;
	int solve(int arr[],int n,int sum)
	{
	    if(n==0 and sum!=0)
	        return 0;
	    if(n==0 and sum==0)
	        return 1;
	       
	    if(dp[n][sum]!=-1)
	        return dp[n][sum];
	    
	    if(arr[n-1]<=sum){
	        dp[n][sum]=solve(arr,n-1,sum-arr[n-1])%mod+solve(arr,n-1,sum)%mod;
	    }
	    else{
	        dp[n][sum]=solve(arr,n-1,sum)%mod;
	    }
	    return dp[n][sum]%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp[n+1][sum+1];
        memset(dp,-1,sizeof(dp));
        return solve(arr,n,sum);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends