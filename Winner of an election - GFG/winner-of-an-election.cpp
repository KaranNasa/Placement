//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        
        unordered_map<string,int> m;
        // vector<string> ans;
        string max_string="";
        int max_count=-1;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(max_count < m[arr[i]]){
                max_count=m[arr[i]];
                max_string=arr[i];
            }
            // max_count=max(max_count,m[arr[i]]);
        }
        for(auto itr:m){
            if(max_count == itr.second and itr.first!=max_string){
                if(itr.first < max_string)
                    max_string=itr.first;
            }
        }
        return {max_string,to_string(max_count)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends