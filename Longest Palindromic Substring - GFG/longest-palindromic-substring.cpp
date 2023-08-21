//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        
          int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));

        string ans="";
        int maxlength=0;

        // for single substring
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=i+diff;j<n;i++,j++){
                if(i==j)
                    dp[i][j]=1;
                
                else if(diff==1){
                    if(s[i] == s[j])
                        dp[i][j]=2;
                }
                else{
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1] != 0)
                            dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }

                if(dp[i][j] > 0 and dp[i][j] > maxlength){
                    maxlength=dp[i][j];
                    ans=s.substr(i,j-i+1);  // sbstring from i,j. Pass index and the length
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends