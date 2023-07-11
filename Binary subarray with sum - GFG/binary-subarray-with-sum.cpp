//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        
        unordered_map<int,int> m;
        int curr_sum=0;
        int count=0;
        
        for(int i=0;i<N;i++){
            curr_sum+=arr[i];
            
            if(curr_sum == target)  // if curr_sum == target then increment the count
                count++;
            
            if(m.find(curr_sum - target)!=m.end())  // if target-curr_sum is present then also increment
                count+=m[curr_sum-target];
            
            // if(m.find(curr_sum)!=m.end())
            //     m[curr_sum]++;
            // else
                m[curr_sum]++;
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
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends