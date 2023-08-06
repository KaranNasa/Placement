//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int index,int n,vector<int> &vis,vector<string> &ans,string curr_ans,string S)
    {
        if(curr_ans.length()==n){
            ans.push_back(curr_ans);
            return;
        }
        
        // for this index, we can pick any value form the array which is not visited
        for(int i=0;i<n;i++){
            if(!vis[i])
            {
                vis[i]=1;
                solve(i+1,n,vis,ans,curr_ans+S[i],S);
                vis[i]=0;   // backtrack
            }
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        int n=S.length();
        vector<int> vis(n,0);
        vector<string> ans;
        string curr_ans="";
        
        solve(0,n,vis,ans,curr_ans,S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends