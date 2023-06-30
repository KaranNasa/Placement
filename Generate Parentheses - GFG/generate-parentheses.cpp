//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(string curr_ans,vector<string> &ans,int n,int open,int close)
    {
       // At any step, 
        // left or right shoud not be greater than n
        // right para count shoud not be greater than left para count
        if(open>n || close>n || close-open>0)
            return;
        // if left and right para counts equals to n, this is required combination
        if(open == close && open == n ){
            ans.push_back(curr_ans);
            return;
        }
        if(open<n)   // check if still we can add left para
            solve(curr_ans+'(',ans,n,open+1,close);  // decrease left count by 1

        if(close<n)  // check if still we can add right para
            solve(curr_ans+')',ans,n,open,close+1);  // decrease right count by 1
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string curr_ans="";
        solve(curr_ans,ans,n,0,0);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends