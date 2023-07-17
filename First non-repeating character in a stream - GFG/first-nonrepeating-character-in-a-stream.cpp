//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
		    unordered_map<char,int> m;
		    queue<char> q;
		    int n=A.length();
		    for(int i=0;i<n;i++){
		        m[A[i]]++;
		        q.push(A[i]);
		        while(!q.empty() and m[q.front()]>1)
		            q.pop();
		           
		        if(q.empty())
		            ans+='#';
		        else
		            ans+=q.front();
		            
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends