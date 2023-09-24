//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> ans;
        vector<int> freq(n,0);
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            
            if(freq[arr[i]] == 2)
                ans.push_back(arr[i]);
        }
        sort(ans.begin(),ans.end());
        if(ans.size()==0)
            return {-1};
        else
            return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends