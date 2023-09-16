//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long int mod=1000000007;
    long long solve(int curr_step,int n,vector<int> &dp)
    {
        if(curr_step > n)
            return 0;
        
        if(curr_step == n)
            return 1;
        
        if(dp[curr_step]!=-1)
            return dp[curr_step];
            
        return dp[curr_step]=(solve(curr_step+1,n,dp)%mod + solve(curr_step+2,n,dp)%mod + solve(curr_step+3,n,dp)%mod)%mod;
    }
    long long countWays(int n)
    
    {
        
        // your code here
        if(n==1)
            return 1;
        
        // int count=0;
        vector<int> dp(n+1,-1);
        long long ans=solve(0,n,dp);
        
        return ans%mod;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends