//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        // store left_max
        vector<int> left(n);
        left[0]=arr[0];
        int maxi=arr[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i]);
            left[i]=maxi;
        }
        
        vector<int> right(n);
        right[n-1]=arr[n-1];
        maxi=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,arr[i]);
            right[i]=maxi;
        }
        
        long long total_amount=0;
        for(int i=0;i<n;i++){
            total_amount+=(min(left[i],right[i]) - arr[i]);
        }
        
        return total_amount;
        
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends