//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int start_num=1;
        sort(arr,arr+n);
        int i=0;
        while(i<n){
            if(arr[i] <= 0)
                i++;
            else{
                if(arr[i] == start_num){
                    while(i<n and arr[i]==start_num)
                        i++;
                    start_num++;
                }
                else{
                    return start_num;
                }
            }
        }
        
        return start_num;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends