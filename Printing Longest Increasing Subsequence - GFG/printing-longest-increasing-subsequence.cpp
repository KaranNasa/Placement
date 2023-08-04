//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int> lis(n,1);
        vector<int> index_table(n);
        for(int i=0;i<n;i++){
            index_table[i]=i;
        }
        
        // compute the lis first
        for(int index=0;index<n;index++){
            for(int prev_index=0;prev_index<index;prev_index++){
                if(arr[index] > arr[prev_index]){
                    if(1 + lis[prev_index] > lis[index]){
                        lis[index]=1+lis[prev_index];
                        index_table[index]=prev_index;
                    }
                    // lis[index]=max(lis[index],1 + lis[prev_index]);
                }
            }
        }
        
        // compute the largest lis and its index
        int max1=INT_MIN,lastindex=-1;
        for(int i=0;i<n;i++){
            if(lis[i] > max1){
                max1=lis[i];
                lastindex=i;
            }
        }
        
        // now we have the index now we can 
        vector<int> ans;
        ans.push_back(arr[lastindex]);
        
        while(index_table[lastindex] != lastindex){
            lastindex=index_table[lastindex];
            ans.push_back(arr[lastindex]);
        }
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