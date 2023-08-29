//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int maxChars (string s)
{
    // your code here
    int n=s.length();
    
    int max_len=-1;
    unordered_map<char,int> m;
    
    for(int i=0;i<n;i++){
        if(m.find(s[i])!=m.end()){
            // cout<<i<<" "<<m[s[i]]<<endl;
            max_len=max(max_len,i-m[s[i]]-1);
        }
        else
            m[s[i]]=i;
    }
    
    return max_len;
}