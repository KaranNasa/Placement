//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m;   // curr_sum and index
        int max_length=0;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=A[i];
            if(curr_sum==0)
                max_length=max(max_length,i+1);
            
            if(m.find(curr_sum)!=m.end())
                max_length=max(max_length,i-m[curr_sum]);
            else
                m[curr_sum]=i;
        }
        
        return max_length;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends