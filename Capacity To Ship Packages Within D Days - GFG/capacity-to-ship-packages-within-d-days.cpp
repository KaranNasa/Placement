//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int solve(int arr[],int n,int days,int max_cap)
    {
        int curr_cap=0,total_days=0;
        // cout<<max_cap<<endl;
        for(int i=0;i<n;i++){
            if(curr_cap + arr[i] <= max_cap){
                curr_cap+=arr[i];
            }
            else{
                total_days++;
                curr_cap=arr[i];
            }
            // cout<<curr_cap<<" "<<total_days<<endl;
        }
        if(curr_cap!=0)
            total_days++;

        // cout<<max_cap<<" "<<total_days<<endl;
        return total_days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int sum=0,max1=INT_MIN;
        for(int i=0;i<n;i++){
            max1=max(max1,arr[i]);
            sum+=arr[i];
        }
        
        int s=max1,e=sum;
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;  // this is capacity of ship
            int days_taken=solve(arr,n,d,mid);

            if(days_taken <= d){
                ans=mid;
                e=mid-1;    // now reduce the capacity
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends