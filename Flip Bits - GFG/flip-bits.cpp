//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        
        // replace 0->1 and 1->-1
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1){
                count++;
                a[i]=-1;
            }
            else
                a[i]=1;
        }
        int sum=0,max_sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            max_sum=max(max_sum,sum);
            
            if(sum<0)
                sum=0;
        }
        return max_sum+count;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends