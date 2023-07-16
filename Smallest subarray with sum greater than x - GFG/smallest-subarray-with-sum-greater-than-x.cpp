//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here 
        int i=0,j=0;
        int curr_sum=0,min_length=INT_MAX;
        while(j<n){
            curr_sum+=arr[j];
            if(curr_sum <= x)
                j++;
            else{
                min_length=min(min_length,j-i+1);
                while(curr_sum > x){
                    curr_sum-=arr[i];
                    if(curr_sum <= x){
                        curr_sum+=arr[i];
                        break;
                    }
                    i++;
                }
                min_length=min(min_length,j-i+1);
                j++;
            }
        }
        
        return min_length;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends