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
        int start=0,len=1;  // min length will always be 1
        int low,high;

        for(int i=1;i<n;i++){
            
            // even case
            low=i,high=i-1;
            while(low>=0 and high<n and s[low] == s[high]){
                if(high-low+1 >len){
                    start=low;
                    len=high-low+1;
                }

                low--;
                high++;
            }
            
            // odd case
            low=i-1,high=i+1;

            while(low>=0 and high<n and s[low] == s[high]){
                if(high-low+1 > len){
                    start=low;
                    len=high-low+1;
                }

                high++;
                low--;
            }
        }

        return s.substr(start,len);
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