//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool check(int index,int curr_sum,vector<int> &arr,int k,int n)
    {
         if(index > n || curr_sum > k)
            return false;
            
        if(curr_sum==k)
            return true;
        
        return (check(index+1,curr_sum + arr[index],arr,k,n) || check(index+1,curr_sum,arr,k,n));
        
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return check(0,0,arr,k,n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends