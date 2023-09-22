//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        vector<long long> pref(n);
        vector<long long> suff(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            pref[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=a[i];
            suff[i]=sum;
        }
        
        // int ans=-1;
        for(int i=0;i<n;i++){
            int left=0,right=0;
            if(i-1>=0)
                left=pref[i-1];
            if(i+1<n)
                right=suff[i+1];
            
            if(left==right)
                return (i+1);
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends