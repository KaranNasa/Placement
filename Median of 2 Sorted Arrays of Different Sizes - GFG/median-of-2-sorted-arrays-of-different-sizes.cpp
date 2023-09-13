//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n1=array1.size(),n2=array2.size();
        if(n1>n2)
            return MedianOfArrays(array2,array1);
        
        int n=n1+n2;
        int left_half=(n1+n2+1)/2;
        
        int s=0,e=n1;
        while(s<=e){
            int mid1=s+(e-s)/2;
            int mid2=left_half-mid1;
            
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1)
                r1=array1[mid1];
            if(mid2<n2)
                r2=array2[mid2];
            if(mid1-1>=0)
                l1=array1[mid1-1];
            if(mid2-1>=0)
                l2=array2[mid2-1];
            
            if(l1<=r2 and l2<=r1){
                if(n%2==1)
                    return max(l1,l2);
                else
                    return (double)((max(l1,l2) + min(r1,r2) )/ 2.0);
            }
            else if(l1 > r2)
                e=mid1-1;
            else
                s=mid1+1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends