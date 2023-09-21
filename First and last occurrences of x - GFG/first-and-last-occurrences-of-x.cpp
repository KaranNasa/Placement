//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve1(int arr[],int n,int x)
    {
        int s=0,e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid] == x)
            {
                ans=mid;
                e=mid-1;
            }
            else if(arr[mid] > x)
                e=mid-1;
            else
                s=mid+1;
        }
        return ans;
    }
    int solve2(int arr[],int n,int x)
    {
        int s=0,e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==x){
                ans=mid;
                s=mid+1;
            }
            else if(arr[mid] > x)
                e=mid-1;
            else
                s=mid+1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first_index=solve1(arr,n,x);
        if(first_index==-1)
            return {-1,-1};
        
        int second_index=solve2(arr,n,x);
        return {first_index,second_index};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends