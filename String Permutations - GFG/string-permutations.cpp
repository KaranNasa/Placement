//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int index,string S,int n,vector<string> &ans)
    {
        if(index==n){
            ans.push_back(S);
            return;
        }
        for(int i=index;i<n;i++){
            swap(S[i],S[index]);
            solve(index+1,S,n,ans);
            swap(S[i],S[index]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        solve(0,S,S.length(),ans);
        
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