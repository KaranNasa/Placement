//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        
        // same as prev. Sort the array and then use the 2 pointer approach
        sort(A,A+n);
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i+1;
            int right=n-1;
            while(left < right){
                int sum=A[i] + A[left] + A[right];
                if(sum == X)
                    return true;
                
                else if(sum > X)
                    right--;
                else
                    left++;
            }
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends