//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        unordered_map<char,int> m;
        int max_length=-1;
        int i=0,j=0,n=s.length();
        
        while(j<n){
            m[s[j]]++;
            if(m.size()<k)
                j++;
            else if(m.size()==k){
                max_length=max(max_length,j-i+1);
                j++;
            }
            else{
                while(i<n and m.size()>k){
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    
                    i++;
                }
                
                // now size again becomes equal to k
                max_length=max(max_length,j-i+1);
                j++;
            }
        }
        
        return max_length;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends