//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> lis(n,1);
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int maxi=-1,max_index=-1;
        
        for(int index=0;index<n;index++){
            for(int prev_index=0;prev_index<index;prev_index++){
                if(arr[index] > arr[prev_index] and lis[prev_index] + 1 > lis[index]){
                    parent[index]=prev_index;
                    lis[index]=lis[prev_index] + 1;
                }
            }
            if(lis[index] > maxi)
            {
                maxi=lis[index];
                max_index=index;
            }
        }
        
        // cout<<maxi<<" "<<max_index<<endl;
        vector<int> ans;
        while(max_index != parent[max_index]){
            ans.push_back(arr[max_index]);
            max_index=parent[max_index];
        }
        ans.push_back(arr[max_index]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends