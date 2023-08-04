//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        
        sort(arr.begin(),arr.end());    // we do this so that we can get any order.
        
        vector<int> lis(n,1);
        vector<int> backtrack(n);
        
        for(int i=0;i<n;i++)
            backtrack[i]=i;
        
        int max1=INT_MIN,max_index=-1;
        for(int index=0;index<n;index++){
            for(int prev_index=0;prev_index<index;prev_index++){
                
                if(arr[index]%arr[prev_index]==0 and lis[prev_index] + 1 > lis[index]){
                    lis[index]=lis[prev_index] + 1;
                    backtrack[index]=prev_index;
                }
            }
            if(lis[index] > max1){
                max1=lis[index];
                max_index=index;
            }
        }
        
        vector<int> ans;
        ans.push_back(arr[max_index]);
        
        while(max_index!=backtrack[max_index]){
            max_index=backtrack[max_index];
            ans.push_back(arr[max_index]);
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
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends