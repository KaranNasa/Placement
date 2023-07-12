//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

void solve(string &ans,int n,string str)
{
    if(n==0){
        return;
    }
    
    char ch=str[n-1];
    solve(ans,n-1,str);
    ans=ch+ans;
}
string reverseWord(string str){
    
  //Your code here
  int n=str.length();
  string ans="";
  solve(ans,n,str);
  
  return ans;
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends