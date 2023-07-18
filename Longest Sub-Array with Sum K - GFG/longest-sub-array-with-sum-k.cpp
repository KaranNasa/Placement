//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        // using prefix sum and hashing. This work only for positive numbers
        unordered_map<int,int> m;
        int max_length=0;
        int curr_sum=0,j=0;
        while(j<N){
            curr_sum+=A[j];
            if(curr_sum==K)
                max_length=max(max_length,j+1);
            
            int rem=curr_sum-K;
            if(m.find(rem)!=m.end())
                max_length=max(max_length,j-m[rem]+1);
        
            j++;
            if(m.find(curr_sum)==m.end())   // the only change when negative numbers are present
                m[curr_sum]=j;
        }
        return max_length;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends