//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int n, int k)
    {
        // code here
        unordered_map<int,int> m;   // map is for curr_sum count
        int count=0;
        int curr_sum=0,j=0;
        while(j<n){
            curr_sum+=Arr[j];
            if(curr_sum==k)
                count++;
            
            int rem=curr_sum - k;
            if(m.find(rem)!=m.end())
                count+=m[rem];
            
            m[curr_sum]++;
            j++;
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends